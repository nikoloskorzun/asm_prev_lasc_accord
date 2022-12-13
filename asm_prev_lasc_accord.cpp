

#include <iostream>

//Организация ЭВМ
//Организация ввода вывода с помощью ассемблерной архитектуры


//В массиве из 10 чисел обнулить все элементы, значение которых меньше среднего арифметического элементов данного массива.

using namespace std;

int main()
{
	int16_t A[10]; //массив и максимальный элемент
	char inputting[] = "%hd", outputting[] = "%hd "; //массив ввода символов и вывода символов
	//Важно не допускать переполнений, ведь защиты от этого ***** нет
	__asm
	{
		lea esi, A //вносим в регистр индекса источника адрес массива (первый элемент)
		mov ecx, 10
		Inputting:
		push esi
			push ecx
			push esi
			lea eax, inputting
			push eax
			call scanf
			add esp, 8 //ecx + esi = 8
			pop ecx //берем кол-во элементов массива
			pop esi //берем адрес массива
			add esi, 2; //переходим на следуюий элемент, пока не закончатся 2 = int16_t
		loop Inputting // проверяем-отнимаем ecx




			mov esi, 0 //обнуляем (массив)
			mov cx, 10 //2bytes счетчик массива
			mov ax, 0 //в максимальном теперь ноль
			
			C: //суммируем все в ax
			mov bx, A[esi * 2]
			inc esi
			add ax, bx
			dec cx
			cmp cx, 0
			jne C



			//делим на 10 и получаем ср арифм
			mov bx, 10
			
			mov dx, 0 //чтобы делить отрицательные числа, необходимо расширить число до ах:дх и в дх занести ноль
			cwd //расширение в ах:дх
			idiv bx


			




	//-5000 -500 -5000 -5000 55 -500 -5000 -500 -500 -500
	//1 2 3 4 5 6 7 8 9 0
	// 3 5 1 -4 2 -6 8 1 5 9




				mov esi, 0 //обнуляем (массив)
				mov cx, 10 //2bytes счетчик массива
			
				mov bx, ax
				

				C1:
				//крутимся по массиву и зануляем при a[<iter>] < ax == ср. арифм
				mov ax, A[esi*2]
				cmp bx, ax
				jl Next //если элемент меньше нуля, то мы нашли отрицательный, иначе  - переход по метке
				mov ax, 0
				mov A[esi * 2], ax
				Next:
				inc esi
				dec cx
				cmp cx, 0
				jne C1
				//закончили



				

			Exit :
			mov ecx, 10
			lea esi, A
			Outputting :
			push esi
			push ecx

			push[esi]
			lea eax, outputting
			push eax
			call printf // вызываем printf согласно форматированию outputting печатая [esi] == a[esi]
			add esp, 8
			pop ecx
			pop esi
			add esi, 2
			loop Outputting
	}


	//работает и слава богу
	return 0;
}
