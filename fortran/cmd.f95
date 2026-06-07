program cmd
    implicit none
    
    ! переменные 
    character(len=64) :: command
    character :: sym 
    real :: x, y

    print *, "Welcome to the FortranCMD!"
    
    ! бесконечный цикл
    do while (.true.)
        print *, '> '

        read(*,*) command 

        if (command == 'help') then
            ! на большее фантазии не хватило
            
            print *, '|=========================================================|'
            print *, '| 1.help - output all commands                            |'
            print *, '| 2.calc - run the calculator                             |'
            print *, '| 3.logo - output the logo fortran and label `cmd`        |'
            print *, '| 4.exit - exit the shell                                 |'
            print *, '|=========================================================|'
        else if (command == 'calc') then 
            
            print *, '[CALCULATOR]'
            read(*,*) x,sym,y

            if (sym == '+') then
                print *, 'Sum: ', x + y
            else if (sym == '-') then 
                print *, 'Difference: ', x - y
            else if (sym == '*') then 
                print *, 'Product: ', x * y
            else if (sym == '/') then 
                if (x == 0) then 
                    print *, 'Division by zero!'
                else if (y == 0) then 
                    print *, 'Division by zero!'
                else 
                    print *, 'Quotient: ', x / y 
                end if
            end if
        
        else if (command == 'logo') then 
            call print_fetch()
        else if (command == 'exit') then 
            exit 
        else 
            print *, 'govno peredelivay'
        end if
    end do 

contains 

    subroutine print_fetch()
    implicit none 

        print *, '____________'
        print *, '\| |------\|' 
        print *, ' | |___|      ______   ____   ____  ______'
        print *, ' | ____|     /      \  |  \  /   |  |     \'
        print *, ' | |   |    |          |   \/    |  |     |'
        print *, ' | |        |          |         |  |     |'
        print *, ' | |        |          |         |  |     |'
        print *, '_|_|_        \______/  |         |  |_____/'   
    end subroutine print_fetch

end program cmd
