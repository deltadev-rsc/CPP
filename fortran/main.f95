! ||=================================================||
! ||  решил по фану покодить на фортране.            ||
! ||  калькуляктер сделал сам, а пример с цилиндром  ||
! ||  взят уже из документации по языку.             ||
! ||=================================================||

module mod 
    implicit none
    integer :: n = 2
end module 

program main
    implicit none

    ! объявление переменных 
    character :: sym 
    integer :: x, y
    real :: pi, rad, height, area, vol
    real :: xr 

    ! установка их значений и операции с ними
    pi = 3.1415927

    ! калькулятор
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
    
    ! cилиндер
    print *, '[CYLINDER]'

    print *, 'Enter cylinder base radius: '
    read(*,*) rad 

    print *, 'Enter cylinder height: '
    read(*,*) height 
    
    area = pi * rad**2
    vol = area * height

    print *, 'Cylinder radius is: ', rad
    print *, 'Cylinder height is: ', height
    print *, 'Cylinder base area is: ', area 
    print *, 'Cylinder volume is: ', vol

    ! Цифры какие-то для примера использования блока
    block 
        use mod, only: n
        real :: y 
        y = 2.0 
        xr = y ** n 
        print *, '[NUMBERS]'
        print *, y
    end block
    print *, xr
end program main 
