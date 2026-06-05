// Laboratory_14-15_Zboryk_Anton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <windows.h>
#include "Figure.h"
#include "Circle.h"
#include "Line.h"
#include "Closed_broken_line.h"
#include "Correct_polygon.h"
#include "Rectangl.h"
#include "Sector.h"
#include "Point2D.h"

int getSafeInt() {
    int value;
    while (!(std::cin >> value)) {
        std::cin.clear(); // Скидаємо прапорець помилки cin
        std::cin.ignore(10000, '\n'); // Очищаємо буфер від неправильних символів
        std::cout << "Помилка введення! Будь ласка, введіть ціле число: ";
    }
    std::cin.ignore(10000, '\n'); // Очищаємо залишок рядка
    return value;
}

void getSafeDouble(int minValue, double** values, int size) {
    for (int i = 0; i < size; i += 1) {
        // Якщо зчитування невдале або число не відповідає умові
        while (!(std::cin >> *values[i]) || *values[i] <= minValue) {
            std::cin.clear(); // Скидаємо стан помилки, якщо користувач ввів букву
            std::cin.ignore(10000, '\n'); // Знищуємо саме той некоректний символ, що зламав зчитування
            std::cout << "Помилка введення! Будь ласка, введіть число більше " << minValue << std::endl << "Будь ласка, перевведіть параметр " << (i + 1) << " та всі наступні параметри фігури: ";
        }
    }
    // Очищаємо залишок рядка (наприклад, натискання Enter) після того, як ВСІ елементи зчитано успішно
    std::cin.ignore(10000, '\n');
}


void showMenu() {
    std::cout << "\nОберіть примітив для додавання:" << std::endl;
    std::cout << "1 - Лінія" << std::endl;
    std::cout << "2 - Прямокутник" << std::endl;
    std::cout << "3 - Коло" << std::endl;
    std::cout << "4 - Правильний багатокутник (5-8 сторін)" << std::endl;
    std::cout << "5 - Сектор" << std::endl;
    std::cout << "6 - Замкнена ламана" << std::endl;
    std::cout << "7 - Розрахувати аналітику та завершити" << std::endl;
    std::cout << "0 - Вихід без розрахунку" << std::endl;
    std::cout << "Ваш вибір: ";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<Figure*> userCanvas;

    std::cout << "Найпростіший графічний редактор аналізу зображень\n";
    int choice=-1;
    while (choice !=0) {
        showMenu();

        choice = getSafeInt();

        try {
            if (choice == 1) {
                double x1, y1, x2, y2;

                std::cout << "Введіть X1 Y1 X2 Y2 (через пробіл): ";
				double* coords[] = { &x1, &y1, &x2, &y2 };
                getSafeDouble(std::numeric_limits<int>::lowest(), coords, 4);
                userCanvas.push_back(new Line(Point2D(x1, y1), Point2D(x2, y2)));
                std::cout << "Лінію додано.\n";
            }
            else if (choice == 2) {
                double w, h;
                std::cout << "Введіть ширину та висоту (в мм): ";
				double* dimensions[] = { &w, &h };
                getSafeDouble(0, dimensions, 2);
                userCanvas.push_back(new Rectangl(w, h));
                std::cout << "Прямокутник додано.\n";
            }
            else if (choice == 3) {
                double r;
                std::cout << "Введіть радіус кола (в мм): ";
				double* radius[] = { &r };
                getSafeDouble(0, radius, 1);
                userCanvas.push_back(new Circle(r));
                std::cout << "Коло додано.\n";
            }
            else if (choice == 4) {
                int sides;
                double length, sides_double;
                std::cout << "Введіть кількість сторін (5-8) та довжину сторони: ";
                double* lengthPtr[] = { &sides_double, &length };
                getSafeDouble(0, lengthPtr, 2);
                sides = (int)sides_double;

                auto polygon = new CorrectPolygon(sides, length);

                while (true) {
                    std::cout << "Бажаєте автоматично згенерувати вписане (1) чи описане (2) коло? (0 - ні): ";
                    int relation;
                    relation = getSafeInt();

                    if (relation == 1) {
                        userCanvas.push_back(polygon->createInscribedCircle());
                        std::cout << "Вписане коло додано.\n";
						break;
                    }
                    else if (relation == 2) {
                        userCanvas.push_back(polygon->createCircumscribedCircle());
                        std::cout << "Описане коло додано.\n";
						break;
                    }
                    else if (relation == 0) {
                        break;
                    }
                    else {
                        std::cout << "Некоректний вибір. Спробуйте знову.\n";
					}
                }

                userCanvas.push_back(polygon);
                std::cout << "Багатокутник додано.\n";
            }
            else if (choice == 5) {
                double r, angle;
                std::cout << "Введіть радіус та кут сектора в градусах: ";
				double* sectorParams[] = { &r, &angle };
                getSafeDouble(0, sectorParams, 2);
                userCanvas.push_back(new Sector(r, angle));
                std::cout << "Сектор додано.\n";
            }
            else if (choice == 6) {
                int count;
                std::cout << "Введіть кількість точок ламаної: ";
                count = getSafeInt();
                std::vector<Point2D> pts;
                for (int i = 0; i < count; i+=1) {
                    double x, y;
                    std::cout << "Точка " << (i + 1) << " (X Y): ";
                    double* coords[] = { &x, &y };
                    getSafeDouble(std::numeric_limits<int>::lowest(), coords, 2);
                    pts.emplace_back(x, y);
                }
                userCanvas.push_back(new Closed_broken_line(pts));
                std::cout << "Замкнену ламану додано.\n";
            }
            else if (choice == 7) {
				break;
            }
            else {
                std::cout << "Некоректний вибір.\n";
            }
        }
        catch (const std::exception& ex) {
            std::cout << "Помилка: " << ex.what() << " Спробуйте знову.\n";
        }
    }

    std::cout << "\nРезультати Аналізу графічних примітив\n";
    double totalArea = 0.0;
    double totalPerimeter = 0.0;

    std::cout << std::fixed << std::setprecision(4);
    for (size_t i = 0; i < userCanvas.size(); i+=1) {
        double area = userCanvas[i]->getArea();
        double perimeter = userCanvas[i]->getPerimeter();
        totalArea += area;
        totalPerimeter += perimeter;

        std::cout << (i + 1) << ". " << userCanvas[i]->getName() << " -> Площа: " << area << " кв.мм, Периметр/Довжина: " << perimeter << " мм\n";
    }

    const double inkConsumptionPerMm2 = 12.0; // мл / мм^2
    double totalInkVolume = totalArea * inkConsumptionPerMm2;
;
    std::cout << "\ni.  Сумарна площа створених фігур: " << totalArea << " мм^2"<< std::endl;
    std::cout << "ii. Необхідний об'єм фарби для друку зображення: " << totalInkVolume << " мл (із розрахунку " << inkConsumptionPerMm2 << " мл/мм^2)" << std::endl;;

    for (Figure* fig : userCanvas) {
        delete fig;
    }
    userCanvas.clear();
    
    return 0;
}


