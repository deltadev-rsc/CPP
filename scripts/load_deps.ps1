function Install-Compiler {
    # Установка Chocolatey (если его нет)
    Set-ExecutionPolicy Bypass -Scope Process -Force
    [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
    iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))

    # Установка Gfortran, GCC, G++. В mingw есть все эти компиляторы.
    choco install mingw -y
}

function Install-Ncurses-Lib {
    # Установка MSYS2
    $msys2URL = "https://github.com/msys2/msys2-installer/releases/download/2024-01-14/msys2-x86_64-20240114.exe"
    $msys2Installer = "C:\msys2-installer.exe"
    $msys2Path = "C:\msys2"

    # Загрузка
    Write-Host "Загрузка MSYS2..."
    Invoke-WebRequest -Uri $msys2URL -OutFile $msys2Installer

    # Установка
    Write-Host "Установка MSYS2..."
    & $msys2Installer -InstallPath $msys2Path -NoPath -NoRegistry -NoAssociation

    # Инициализация MSYS2
    Write-Host "Инициализация MSYS2..."
    & "$msys2Path\msys2_shell.cmd" -defterm -here -no-start -c "pacman -Syu --noconfirm"

    # Установка ncurses через pacman
    Write-Host "Установка ncurses..."
    & "$msys2Path\msys2_shell.cmd" -defterm -here -no-start -c "pacman -S --noconfirm mingw-w64-x86_64-ncurses"

    # Добавление в PATH
    $envPath = [Environment]::GetEnvironmentVariable("PATH", "Machine")
    if ($envPath -notlike "*msys2*") {
        [Environment]::SetEnvironmentVariable("PATH", "$envPath;$msys2Path\mingw64\bin", "Machine")
        Write-Host "PATH обновлён"
    }

    Remove-Item $msys2Installer
    Write-Host "Установка завершена!"
}

Install-Compiler
Install-Ncurses-Lib
