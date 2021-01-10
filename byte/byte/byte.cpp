#include <iostream>//Для работы с клавиатурой
#include <fstream>//Для работы с файлами
#include <bitset>

#define FLOAT_ARRAY_SIZE 5
#define OUTPUT_INT_ARRAY_SIZE 10

// опции флагов
#define  FLAG_option_1  0
#define  FLAG_option_2  1
#define  FLAG_option_3  2
#define  FLAG_option_4  3
#define  FLAG_option_5  4
#define  FLAG_option_6  5
#define  FLAG_option_7  6
#define  FLAG_option_8  7

struct Msg {
	std::bitset<64> mask = 0xAAAAAAAAAAAAAAAA;
	//uint64_t mask = 0xAAAAAAAAAAAAAAAA;
	//uint8_t _flag = FLAG_option_1; //битовый флаг шестнадцатиричный литерал 0000 0001
	std::bitset<8> bitsFLAG = FLAG_option_8; //8 бит
	int32_t id = 2111111111;
	int32_t n = 1999999999;

	float arrayMSG[FLOAT_ARRAY_SIZE] = { 0.0, 1.1, 2.2,3.3,4.4 };
};

//запись структуры в массив
int struct2Array(Msg *msg, int32_t *arrMsg, uint32_t size) {

	int8_t* ptr_arrMsg = (int8_t*)arrMsg;
	int8_t* ptr_msg = (int8_t*)msg;

	size_t sz_arrMsg = sizeof(*arrMsg) * size;
	size_t sz_msg = sizeof(*msg);

	//проверка на несоответствие размера sz_arrMsg != sz_msg0
	if (sz_arrMsg != sz_msg) {
		std::cerr << "Ошибка размеры sz_arrMsg и sz_msg0 не совпадают" << std::endl;
		return 1;
	}

	for (size_t i = 0; i < sz_msg; i++) {
		*(ptr_arrMsg + i) = *(ptr_msg + i);
	}
	return 0;
};

//запись массива в структуру
int array2Struct(int32_t *arrMsg, uint32_t size, Msg *msg) {

	int8_t* ptr_arrMsg = (int8_t*)arrMsg;
	int8_t* ptr_msg = (int8_t*)msg;

	size_t sz_arrMsg = sizeof(*arrMsg) * size;
	size_t sz_msg = sizeof(*msg);

	//проверка на несоответствие размера sz_arrMsg != sz_msg1
	if (sz_arrMsg != sz_msg) {
		std::cerr << "Ошибка размеры sz_arrMsg и sz_msg1 не совпадают" << std::endl;
		return 2;
	}

	for (size_t i = 0; i < sz_msg; i++) {
		*(ptr_msg + i) = *(ptr_arrMsg + i);
	}
	return 0;
};

//сохранение массива в файл
int arr2File(int32_t *arrMsg, uint32_t size, std::string fileName) {
	std::ofstream file;
	file.open(fileName, std::ios::binary);

	int8_t* ptr_arrMsg = (int8_t*)arrMsg;
	size_t sz_arrMsg = sizeof(*arrMsg) * size;

	for (size_t i = 0; i < sz_arrMsg; i++) {
		file << *(ptr_arrMsg + i);
	}

	file.close();

	return 0;
};

//вывод массива из файла
int file2Arr(std::string fileName, int32_t *arrMsg, uint32_t size) {

	std::ifstream file;
	file.open(fileName, std::ios::in || std::ios::binary);
	int8_t* ptr_arrMsg = (int8_t*)arrMsg;
	size_t sz_arrMsg = sizeof(*arrMsg) * size;

	for (size_t i = 0; i < sz_arrMsg; i++) {
		file.read((char*)ptr_arrMsg, sz_arrMsg);

	
	}

	file.close();
	return 0;
};

int main()
{
	setlocale(LC_ALL, "Rus");

	int32_t arrMsg[OUTPUT_INT_ARRAY_SIZE] = {1999999999};
	int32_t arrMsgInput[OUTPUT_INT_ARRAY_SIZE] = {};

	Msg msg0;
	Msg msg1 = {
		0,
		0,
		0,
		0,
		{0,0,0,0,0}
	};

	std::cout << "Размер Msg = "<< sizeof(Msg) << std::endl;
	std::cout << "Размер arrMsg = " << sizeof(arrMsg) << std::endl;
	std::cout << "Размер msg0 = " << sizeof(msg0) << std::endl;
	std::cout << "Размер msg1 = " << sizeof(msg1) << std::endl;
	
	

	struct2Array(&msg0, arrMsg, OUTPUT_INT_ARRAY_SIZE);
	arr2File(arrMsg, OUTPUT_INT_ARRAY_SIZE, "File.bin");
	file2Arr("File.bin", arrMsgInput, OUTPUT_INT_ARRAY_SIZE);
	array2Struct(arrMsgInput, OUTPUT_INT_ARRAY_SIZE, &msg1);


	std::cout << " " << std::endl;




	return 0;
}