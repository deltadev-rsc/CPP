package distros

import (
	"fmt"
	"os"
	"os/exec"
	"strings"
)

const RESET_COLOR = "\x1b[0m"
const RED_COLOR = "\x1b[31m"
const GREEN_COLOR = "\x1b[32m"
const YELLOW_COLOR = "\x1b[33m"
const BLUE_COLOR = "\x1b[34m"
const MAGENTA_COLOR = "\x1b[35m"
const CYAN_COLOR = "\x1b[36m"

func GetUserName() (string, error) {
	cmd := exec.Command("whoami")
	output, err := cmd.Output()
	
	if err != nil {
		return "", fmt.Errorf("ошибка при выполнении команды: %v", err)
	}

	username := string(output[:len(output) - 1])
	return username, nil
}

func GetHostName() (string, error) {
	cmd := exec.Command("uname", "-n")
	output, err := cmd.Output()
	
	if err != nil {
		return "", fmt.Errorf("ошибка при выполнении команды: %v", err)
	}

	hostname := strings.TrimSpace(string(output))
	return hostname, nil 
}

func GetOperatingSystemName() (string, error) {
	cmd := exec.Command("uname", "-o")
	output, err := cmd.Output()

	if err != nil {
		return "", fmt.Errorf("ошибка при выполнении команды: %v", err)
	}

	osname := strings.TrimSpace(string(output))
	return osname, nil
}

func GetKernel() (string, error) {
	cmd := exec.Command("uname", "-sr")
	output, err := cmd.Output()

	if err != nil {
		return "", fmt.Errorf("ошибка при выполнении команды: %v", err)
	}

	kernel := strings.TrimSpace(string(output))
	return kernel, nil
}

func GetShell() (string) {
	shell := "SHELL"

	if val := os.Getenv(shell); val != "" {
		return val 
	}

	return "Unknown"
}

func GetDesktopEnvironment() (string) {
	vars := []string { "XDG_CURRENT_DESKTOP", "DESKTOP_SESSION", "GDMSESSION" }

	for _, v := range vars {
		if val := os.Getenv(v); val != "" {
			return val 
		}
	}

	return "Unknown"
}

func ArtixFetch() {
	username, err := GetUserName()
	hostname, err := GetHostName()
	osname, err := GetOperatingSystemName()
	kernel, err := GetKernel() 
	shell := GetShell()
	de_wm := GetDesktopEnvironment()
	if err != nil {
		fmt.Println("Ошибащка: ", err)
		return
	}

	fmt.Println("")
	fmt.Println(CYAN_COLOR, "            ▟▙              ", RESET_COLOR)
	fmt.Println(CYAN_COLOR, "           ▟██▙             ", RESET_COLOR, CYAN_COLOR,  " User:", username,    RESET_COLOR)          
	fmt.Println(CYAN_COLOR, "          ▟████▙            ", RESET_COLOR, MAGENTA_COLOR,  "───────────────────",  RESET_COLOR)
	fmt.Println(CYAN_COLOR, "         ▟██████▙           ", RESET_COLOR, CYAN_COLOR,  "󰌢 Host:",    hostname, RESET_COLOR)
	fmt.Println(CYAN_COLOR, "            ▜████▙          ", RESET_COLOR, CYAN_COLOR,  " OS:",      osname,   RESET_COLOR)
	fmt.Println(CYAN_COLOR, "       ▟██▙    ▜██▙         ", RESET_COLOR, CYAN_COLOR,  " Kernel:",  kernel,   RESET_COLOR) 
	fmt.Println(CYAN_COLOR, "      ▟██████▙    ▜▙        ", RESET_COLOR, CYAN_COLOR,  " Shell:",   shell,    RESET_COLOR) 
	fmt.Println(CYAN_COLOR, "     ▟██████████▙           ", RESET_COLOR, CYAN_COLOR,  " DE/WM:",   de_wm,    RESET_COLOR)
	fmt.Println(CYAN_COLOR, "    ▟████████▀    ▟██▙      ", RESET_COLOR, CYAN_COLOR,  "", RESET_COLOR)
	fmt.Println(CYAN_COLOR, "   ▟█████▀      ▀█████▙     ", RESET_COLOR, CYAN_COLOR,  "", RESET_COLOR) 
	fmt.Println(CYAN_COLOR, "  ▟██▀             ▜███▙    ", RESET_COLOR, CYAN_COLOR,  "", RESET_COLOR)
	fmt.Println(CYAN_COLOR, " ▟▀                    ▜▙   ", RESET_COLOR, )
	fmt.Println("")
}
