#include <iostream>//Для работы с клавиатурой
#include <fstream>//Для работы с файлами

#define FLOAT_ARRAY_SIZE 5
#define OUTPUT_INT_ARRAY_SIZE 10

struct Msg {
	uint64_t mask = 0xAAAAAAAAAAAAAAAA;
	int32_t id = 2111111111;
	int32_t n = 1999999999;

	float arrayMSG[FLOAT_ARRAY_SIZE] = { 0.0, 1.1, 2.2,3.3,4.4 };
};

int main()
{
	setlocale(LC_ALL, "Rus");


	int32_t arrMsg[OUTPUT_INT_ARRAY_SIZE] = {1999999999};
	Msg msg0;
	Msg msg1 = {
		0,
		0,
		0,
		{0,0,0,0,0}
	};

	std::cout << "Размер Msg = "<< sizeof(Msg) << std::endl;
	std::cout << "Размер arrMsg = " << sizeof(arrMsg) << std::endl;
	std::cout << "Размер msg0 = " << sizeof(msg0) << std::endl;
	std::cout << "Размер msg1 = " << sizeof(msg1) << std::endl;
	
	int8_t* ptr_arrMsg = (int8_t*)arrMsg;
	int8_t* ptr_msg0 = (int8_t*)&msg0;
	int8_t* ptr_msg1 = (int8_t*)&msg1;
	
	size_t sz_arrMsg = sizeof(arrMsg);
	size_t sz_msg0 = sizeof(msg0);
	size_t sz_msg1 = sizeof(msg1);


	//проверка на несоответствие размера sz_arrMsg != sz_msg0
	if (sz_arrMsg != sz_msg0) {
		std::cerr << "Ошибка размеры sz_arrMsg и sz_msg0 не совпадают" << std::endl;
		return 0;
	}
	
	for (size_t i = 0; i < sz_msg0; i++) {
		*(ptr_arrMsg + i) = *(ptr_msg0 + i);
	}

	//проверка на несоответствие размера sz_arrMsg != sz_msg1
	if (sz_arrMsg != sz_msg1) {
		std::cerr << "Ошибка размеры sz_arrMsg и sz_msg1 не совпадают" << std::endl;
		return 0;
	}

	for (size_t i = 0; i < sz_msg1; i++) {
		*(ptr_msg1 + i) = *(ptr_arrMsg + i);
	}
	std::cout << " ";






	system("pause");
	return 0;
}