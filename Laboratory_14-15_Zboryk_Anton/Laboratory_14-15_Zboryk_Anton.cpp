// Laboratory_14-15_Zboryk_Anton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
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

void showMenu() {
    std::cout << "\nОберіть примітив для додавання:\n"
        << "1. Лінія\n"
        << "2. Прямокутник\n"
        << "3. Коло\n"
        << "4. Правильний багатокутник (5-8 сторін)\n"
        << "5. Сектор\n"
        << "6. Замкнена ламана\n"
        << "7. Розрахувати аналітику та завершити\n"
		<< "0. Вихід без розрахунку\n"
        << "Ваш вибір: ";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //std::vector<std::unique_ptr<Figure>> userCanvas;
    std::vector<Figure*> userCanvas;
    //bool running = true;

    std::cout << "Найпростіший графічний редактор аналізу зображень\n";
    int choice=-1;
    while (choice !=0) {
        showMenu();

        choice = getSafeInt();

        try {
            if (choice == 1) {
                double x1, y1, x2, y2;
                std::cout << "Введіть X1 Y1 X2 Y2 (через пробіл): ";
                std::cin >> x1 >> y1 >> x2 >> y2;
                userCanvas.push_back(new Line(Point2D(x1, y1), Point2D(x2, y2)));
                std::cout << "Лінію додано.\n";
            }
            else if (choice == 2) {
                double w, h;
                std::cout << "Введіть ширину та висоту (в мм): ";
                std::cin >> w >> h;
                userCanvas.push_back(new Rectangl(w, h));
                std::cout << "Прямокутник додано.\n";
            }
            else if (choice == 3) {
                double r;
                std::cout << "Введіть радіус кола (в мм): ";
                std::cin >> r;
                userCanvas.push_back(new Circle(r));
                std::cout << "Коло додано.\n";
            }
            else if (choice == 4) {
                int sides;
                double length;
                std::cout << "Введіть кількість сторін (5-8) та довжину сторони: ";
                std::cin >> sides >> length;

                auto polygon = new CorrectPolygon(sides, length);

                std::cout << "Бажаєте автоматично згенерувати вписане (1) чи описане (2) коло? (0 - ні): ";
                int relation;
                std::cin >> relation;

                if (relation == 1) {
                    userCanvas.push_back(polygon->createInscribedCircle().release());
                    std::cout << "Вписане коло додано.\n";
                }
                else if (relation == 2) {
                    userCanvas.push_back(polygon->createCircumscribedCircle().release());
                    std::cout << "Описане коло додано.\n";
                }

                userCanvas.push_back(polygon);
                std::cout << "Багатокутник додано.\n";
            }
            else if (choice == 5) {
                double r, angle;
                std::cout << "Введіть радіус та кут сектора в градусах: ";
                std::cin >> r >> angle;
                userCanvas.push_back(new Sector(r, angle));
                std::cout << "Сектор додано.\n";
            }
            else if (choice == 6) {
                int count;
                std::cout << "Введіть кількість точок ламаної: ";
                std::cin >> count;
                std::vector<Point2D> pts;
                for (int i = 0; i < count; ++i) {
                    double x, y;
                    std::cout << "Точка " << (i + 1) << " (X Y): ";
                    std::cin >> x >> y;
                    pts.emplace_back(x, y);
                }
                userCanvas.push_back(new Closed_broken_line(pts));
                std::cout << "Замкнену ламану додано.\n";
            }
            else if (choice == 7) {
                //running = false;
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

    // ==========================================
    // ВИВЕДЕННЯ РЕЗУЛЬТАТІВ АНАЛІЗУ
    // ==========================================
    std::cout << "\n--- РЕЗУЛЬТАТИ АНАЛІЗУ ЗОБРАЖЕННЯ ---\n";
    double totalArea = 0.0;
    double totalPerimeter = 0.0;

    std::cout << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < userCanvas.size(); ++i) {
        double area = userCanvas[i]->getArea();
        double perimeter = userCanvas[i]->getPerimeter();
        totalArea += area;
        totalPerimeter += perimeter;

        std::cout << (i + 1) << ". " << userCanvas[i]->getName()
            << " -> Площа: " << area << " кв.мм, Периметр/Довжина: " << perimeter << " мм\n";
    }

    const double inkConsumptionPerMm2 = 12.0; // мл / мм²
    double totalInkVolume = totalArea * inkConsumptionPerMm2;

    std::cout << "-------------------------------------\n";
    std::cout << "i.  Сумарна площа створених фігур: " << totalArea << " мм^2\n";
    std::cout << "ii. Необхідний об'єм фарби для друку зображення: " << totalInkVolume << " мл (із розрахунку " << inkConsumptionPerMm2 << " мл/мм^2)\n";

    return 0;
}


