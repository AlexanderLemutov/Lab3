#include <iostream>
#include <cstring>
#include <fstream>
struct excursion {
    std::string name;
    std::string city;
    double price;
};

void addnewexc(const excursion& nexc){
    std::ofstream excursions("excursions.txt", std::ios::app);
    if (excursions.is_open()){
        excursions << nexc.name << "," << nexc.city << "," << nexc.price << std::endl;
        excursions.close();
        std::cout << "Экскурсия успешно добавлена." << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}

void searchbyname(const std::string& fname){
    std::ifstream excursions("excursions.txt");
    if (excursions.is_open()) {
        std::string line;
        bool find = false;
        while (std::getline(excursions, line)) {
            size_t pos = line.find(",");
            std::string tname = line.substr(0, pos);
            if (tname == fname) {
                std::cout << "Экскурсия найдена: " << line << std::endl;
                find = true;
                break;
            }
        }
        if (find == false) {
            std::cout << "Экскурсии с таким названием не существует." << std::endl;
        } 
    } else {
        std::cout << "Не удалось открыть файл для поиска." << std::endl;
    }
}

void sortbypriceu(){
	std::ifstream excursions("excursions.txt");
	if (excursions.is_open()){
		std::string lines[100];
		int count = 0;
		std::string line;
		while (std::getline(excursions, line)){
			lines[count] = line;
			count++;
		}
		excursions.close();
		for (int i = 0; i < count-1; i++){
			for (int j = 0; j < count-i-1; j++){
				size_t pos1 = lines[j].find_last_of(',');
				size_t pos2 = lines[j+1].find_last_of(',');
				double price1 = std::stod(lines[j].substr(pos1+1));
				double price2 = std::stod(lines[j+1].substr(pos2+1));
				if (price1 < price2) {
					std::swap(lines[j], lines[j+1]);
				}
			}
		}
		std::ofstream output("output.txt");
		if (output.is_open()){
			for (int i = 0; i < count; i++){
				output << lines[i] << std::endl;
			}
			output.close();
			std::cout << "Экскурсии отсортированы по стоимости (по убыванию)" << std::endl;
		} else {
			std::cout << "Не удалось открыть файл для записи." << std::endl;
		}
	} else {
		std::cout << "Не удалось открыть файл для сортировки." << std::endl;
	}
}

void sortbypricev(){
	std::ifstream excursions("excursions.txt");
	if (excursions.is_open()){
		std::string lines[100];
		int count = 0;
		std::string line;
		while (std::getline(excursions, line)){
			lines[count] = line;
			count++;
		}
		excursions.close();
		for (int i = 0; i < count-1; i++){
			for (int j = 0; j < count-i-1; j++){
				size_t pos1 = lines[j].find_last_of(',');
				size_t pos2 = lines[j+1].find_last_of(',');
				double price1 = std::stod(lines[j].substr(pos1+1));
				double price2 = std::stod(lines[j+1].substr(pos2+1));
				if (price1 > price2) {
					std::swap(lines[j], lines[j+1]);
				}
			}
		}
		std::ofstream output("output.txt");
		if (output.is_open()){
			for (int i = 0; i < count; i++){
				output << lines[i] << std::endl;
			}
			output.close();
			std::cout << "Экскурсии отсортированы по стоимости (по убыванию)" << std::endl;
		} else {
			std::cout << "Не удалось открыть файл для записи." << std::endl;
		}
	} else {
		std::cout << "Не удалось открыть файл для сортировки." << std::endl;
	}
}

void sortbycitya(){
	std::ifstream excursions("excursions.txt");
	if (excursions.is_open()){
		std::string lines[100];
		std::string line;
		int count = 0;
		while (std::getline(excursions, line)){
			lines[count] = line;
			count++;
		}
		excursions.close();
		for (int i = 0; i < count; i++){
			for (int j = 0; j < count-i-1; j++){
				size_t pos11 = lines[j].find_first_of(',');
				size_t pos12 = lines[j].find_last_of(',');
				std::string city1 = lines[j].substr(pos11+1, ((pos12-1)-(pos11+1)+1));
				size_t pos21 = lines[j+1].find_first_of(',');
				size_t pos22 = lines[j+1].find_last_of(',');
				std::string city2 = lines[j+1].substr(pos21+1, ((pos22-1)-(pos21+1)+1));
				//std::cout << lines[j] << "###" << lines[j+1] << std::endl;
				//std::cout << city1 << "###" << city2 << std::endl;
				if (city1 > city2){
					std::swap(lines[j], lines[j+1]);
				}
				//std::cout << lines[j] << "###" << lines[j+1] << std::endl;
			}
		}
		std::ofstream output("output.txt");
		if (output.is_open()){
			for (int i = 0; i < count; i++){
				output << lines[i] << std::endl;
			}
			output.close();
			std::cout << "Экскурсии отсортированы по месту посещения (по алфавитному порядку)." << std::endl;
		} else {
			std::cout << "Не удалось открыть файл для записи." << std::endl;
		}
	} else {
		std::cout << "Не удалось открыть файл для сортировки." << std::endl;
	}
}

void sortbycityz(){
	std::ifstream excursions("excursions.txt");
	if (excursions.is_open()){
		std::string lines[100];
		std::string line;
		int count = 0;
		while (std::getline(excursions, line)){
			lines[count] = line;
			count++;
		}
		excursions.close();
		for (int i = 0; i < count; i++){
			for (int j = 0; j < count-i-1; j++){
				size_t pos11 = lines[j].find_first_of(',');
				size_t pos12 = lines[j].find_last_of(',');
				std::string city1 = lines[j].substr(pos11+1, pos12-1);
				size_t pos21 = lines[j+1].find_first_of(',');
				size_t pos22 = lines[j+1].find_last_of(',');
				std::string city2 = lines[j+1].substr(pos21+1, pos22-1);
				if (city1 < city2){
					std::swap(lines[j], lines[j+1]);
				}
			}
		}
		std::ofstream output("output.txt");
		if (output.is_open()){
			for (int i = 0; i < count; i++){
				output << lines[i] << std::endl;
			}
			output.close();
			std::cout << "Экскурсии отсортированы по месту посещения (в порядке, обратном алфавитному)." << std::endl;
		} else {
			std::cout << "Не удалось открыть файл для записи." << std::endl;
		}
	} else {
		std::cout << "Не удалось открыть файл для сортировки." << std::endl;
	}
}

void searchbyprice (const double& uprice){
	std::ifstream excursions("excursions.txt");
	if (excursions.is_open()){
		int count = 0;
		std::string lines[100];
		std::string line;
		while (std::getline(excursions, line)){
			lines[count] = line;
			count++;
		}
		excursions.close();
		for (int i = 0; i < count; i++){
			size_t pos = lines[i].find_last_of(',');
			double price = std::stod(lines[i].substr(pos+1));
			if (price <= uprice){
				std::cout << lines[i] << std::endl;
			}
		}
	} else {
		std::cout << "Не удалось открыть файл для поиска по заданной стоимости." << std::endl;
	}
}

int main()
{
    setlocale(LC_ALL, "rus");
    int chose;
    do {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Добавить экскурсию" << std::endl;
        std::cout << "2. Поиск по экскурсии" << std::endl;
        std::cout << "3. Сортировка" << std::endl;
        std::cout << "4. Вывод данных об экскурсиях" << std::endl;
        std::cout << "0. Завершить" << std::endl;
        
        std::cout << "Введите ваш выбор:" << std::endl;
        std::cin >> chose;
        
        switch (chose) {
            case 1: {
                std::cin.ignore();
                std::string ename;
                std::string ecity;
                double eprice;
                excursion newexc;
                do {
                    std::cout << "Введите название экскурсии: " << std::endl;
                    std::cin.ignore();
                    std::getline(std::cin, ename);
                    if (ename.empty()){
                        std::cout << "Ввод прерван." << std::endl;
                        break;
                    }
                        std::cout << "Введите место посещения: " << std::endl;
                        std::getline(std::cin, ecity);
                        std::cout << "Введите цену экскурсии: " << std::endl;
                        std::cin >> eprice;
                        newexc.name = ename;
                        newexc.city = ecity;
                        newexc.price = eprice;
                        addnewexc(newexc);
                    
                } while (!ename.empty());
                break;
            }
            case 2: {
                std::cin.ignore();
                std::string fname;
                std::cout << "Введите название экскурсии: " << std::endl;
                std::getline(std::cin, fname);
                searchbyname(fname);
                break;
            }
            case 3: {
				std::cin.ignore();
				int schose = 0;
				std::cout << "Сортировать по: 1) Месту посещения; 2) Стоимости; " << std::endl;
				std::cin >> schose;
				switch (schose) {
					case 1:{
						int sc2 = 0;
						std::cout << "Сортировать по месту посещения по: 1) Алфавитному порядку; 2) Порядку, обратному алфавитному; " << std::endl; 
						std::cin >> sc2;
						if (sc2 == 1){
							sortbycitya();
						} else if (sc2 == 2){
							sortbycityz();
						}
						break;
				    }
					case 2:{
						int sc2 = 0;
						std::cout << "Сортировать по стоимости: 1) По убыванию; 2) По возрастанию; " << std::endl;
						std::cin >> sc2;
						if (sc2 == 1){
							sortbypriceu();
						} else if (sc2 == 2) {
							sortbypricev();
						}
						break;
					}
					default: {
						std::cout << "Неправильный выбор." << std::endl;
						break;
					}
				}
				break;
			}
            case 4: {
				std::cin.ignore();
				double userprice = 0;
				std::cout << "Введите значение, которое не должна превышать стоимость экскурсии: " << std::endl;
				std::cin >> userprice;
				searchbyprice(userprice);
				break;
			}
            case 0: {
				std::cout << "Программа завершена." << std::endl;
				break;
			}
            default: {
                std::cout << "Неправильный выбор. Попробуйте снова." << std::endl;
				break;
            }
        }
    } while (chose != 0);
    
}
