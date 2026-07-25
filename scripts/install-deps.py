#!/usr/bin/env python3

import subprocess
import sys

def installDependencies():
    packages = [
        'ncurses',
        'gcc',
        'g++',
        'make'
    ]

    if subprocess.run(['id', '-u'], capture_output = True, text = True).stdout.strip() != '':
        print("Этот скрипт необходимо запускать с правами суперпользователя (sudo)")
        sys.exit(1)

    distro = int(input("выберете свою группу дистрибутивов: \n"))
    print("1.arch/arch-based, 2.debian/debian-based")
    if distro == 1:
        try:
            print("Обновление базы данных пакетов и синхронизация с репозиторием...")
            if subprocess.run(['pacman', '-Syu'], check = True) == True:
                print("[ OK ]: база данных пакетов обновлена и синхронизирована с репозиторием!")
            else:
                print("[ FAILED ]: Ошибка при обновлении базы данных пакетов")    

            print("Установка пакетов...")
            result = subprocess.run(['pacman', '-S', '--noconfirm'] + packages,
                                    check = True,
                                    capture_output = True,
                                    text = True)

            print("все пакеты успешно установлены: ")
            for package in packages:
                print(f"- {packages}")
        except subprocess.CalledProcessError as e:
            print("[ FAILED ]: Ошибка при обновлении базы данных пакетов и их установке")
            print(e.stderr)
            sys.exit(1)

    elif distro == 2:
        try:
            print("Обновление базы данных пакетов и инхронизация с репозиторием...")
            if subprocess.run(['apt', 'update'], check = True) == True:
                print("[ OK ]: база данных пакетов обновлена и синхронизирована с репозиторием!")
            else:
                print("[ FAILED ]: Ошибка при обновлении базы данных пакетов")    

            print("Установка пакетов...")
            result = subprocess.run(['apt', 'install'] + packages,
                                    check = True,
                                    capture_output = True,
                                    text = True)

            print("все пакеты успешно установлены: ")
            for package_2 in packages:
                print(f"- {packages}")
        except subprocess.CalledProcessError as e:
            print("Ошибка при обновлении базы данных пакетов и их установке")
            print(e.stderr)
            sys.exit(1)
    else:
        print("")

def main():
    try:
        installDependencies()
    except Exception as e:
        print(f"Произошла непредвиденная ошибка: {e}")
        sys.exit(1)

if __name__ == "__main__"
    main()
