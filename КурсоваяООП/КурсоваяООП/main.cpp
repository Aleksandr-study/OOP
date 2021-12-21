#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "Person.h"
#include "File.h"
#include "TextDocument.h"
#include "ArchiveElement.h"
#include "CatalogComposition.h"

using namespace std;

CatalogComposition enter(CatalogComposition catalog, File* arrayFiles, Person* arrayAuthors, TextDocument** arrayDocuments, ArchiveElement* archives);
void Table();
void write(CatalogComposition* catalog);
void findText(CatalogComposition* catalog);
void findNumber(CatalogComposition* catalog);
template <typename M>
void swap(M* n, M* m);
CatalogComposition search(bool txt, CatalogComposition catalog, File* arrayFiles, Person* arrayAuthors, TextDocument** arrayDocuments, ArchiveElement* archives);
int operator+(File &T, int size);
template <typename T>
void AverageQuantityDocuments(T* x, int y);
template <typename K>
void AverageArchiving(K* x);
int main()
{
	int n;
	CatalogComposition catalog; 
	File* arrayFiles = nullptr;
	Person* arrayAuthors = nullptr;
	TextDocument** arrayDocuments = nullptr;
	ArchiveElement* archives = nullptr;
	std::cout << "\u001B[32mMENU" << std::endl
		<< "[1]\u001B[0m - Entry data" << std::endl
		<< "\u001B[32m[2]\u001B[0m - Read data from text field" << std::endl
		<< "\u001B[32m[3]\u001B[0m - Read data from binary field" << std::endl
		<< "\u001B[32m[4]\u001B[0m - Exit\n";
	cin >> n;
	switch (n)
	{
	case 1://ВВОДИМО И ЗАПИСУЕМО В ФАЙЛ
		catalog = enter(catalog, arrayFiles, arrayAuthors, arrayDocuments, archives);
		break;
	case 2://ЧИТАЕМО З ТЕКСТОВОГО ФАЙЛУ
		catalog = search(1, catalog, arrayFiles, arrayAuthors, arrayDocuments, archives);
		break;
	case 3://ЧИТАЕМО З БІНАРНОГО ФАЙЛУ
		catalog = search(0, catalog, arrayFiles, arrayAuthors, arrayDocuments, archives);
		break;
	case 4:
		break;
	default:
		break;
	}
	//записуємо в файл
	cout << "\nWant to write data to file?\n"
		<< "1 - Yes\n2 - No\n";
	cin >> n;
	switch (n)
	{
	case 1:
		write(&catalog);
		break;
	default:
		break;
	}
	//пошук інформації за текстовим полем.
	cout << "\nWant to find some file in catalog by name?\n"
		<< "1 - Yes\n2 - No\n";
	cin >> n;
	switch (n)
	{
	case 1:
		findText(&catalog);
		break;
	default:
		break;
	}
	//пошук інформації за числовим полем;
	cout << "\nWant to find some file in catalog by size?\n"
		<< "1 - Yes\n2 - No\n";
	cin >> n;
	switch (n)
	{
	case 1:
		findNumber(&catalog);
		break;
	default:
		break;
	}
	cout << "\nWant to swap elements in catalog?\n"
		<< "1 - Yes\n2 - No\n";
	cin >> n;
	switch (n)
	{
	case 1:
		int m;
		cout << "Enter the numbers of 2 archive elememnts you want to swap:\n";
		cin >> n >> m;
		if (n-1 > catalog.getQuality() || m - 1 > catalog.getQuality() || n - 1 < 0 || m - 1 < 0)
		{
			cout << "Inwalid numbers!\n";
		}
		else
		{
			//міняемо місцями за номером 2 елементи архіву за допомогою індексації
			swap(catalog[n + 1], catalog[m + 1]);
			cout << "\Done!\n";
			Table();
			catalog.Show();
		}
		break;
	default:
		break;
	}
	//Звілняємо пам'ять:
	delete[] arrayFiles;
	delete[] arrayAuthors;
	delete[] arrayDocuments;
	cout << endl << "Work is done" << endl;
	return 0;
}

CatalogComposition enter(CatalogComposition catalog, File* arrayFiles, Person* arrayAuthors, TextDocument** arrayDocuments, ArchiveElement* archives)
{
	int s1, s2;
	int allSize = 0;
	std::cout <<std:: endl;
	std::string name, surname, nameOfFile, extension, keyword, placing;
	int d1, d2, m1, m2, y1, y2, size, archivingDegree;
	std::cout << "\n\u001B[32mEnter quantity of archives:\u001B[0m ";
	cin >> s1;
	arrayFiles = new File[s1];
	arrayAuthors = new Person[s1];
	arrayDocuments = new TextDocument * [s1];
	archives = new ArchiveElement[s1];
	for (int i = 0; i < s1; ++i)
	{
		std::cout << "\u001B[32mEnter quantity of documents in " << i+1 << " archive:\u001B[0m ";
		cin >> s2;
		arrayDocuments[i] = new TextDocument[s2];
		std::cout << "\n\u001B[0mArhieve #" << i + 1 << ":\n";
		std::cout << "\u001B[33mEnter day of archive element creation: \u001B[0m";
		cin >> d1;
		std::cout << "\u001B[33mEnter month of archive element creation: \u001B[0m";
		cin >> m1;
		std::cout << "\u001B[33mEnter year of archive element creation: \u001B[0m";
		cin >> y1;
		try
		{
			if (d1 < 1 || d1 > 31)
				throw 1;
			if (m1 < 1 || m1 > 12)
				throw 2;
			if (y1 < 1900 || y1 > 2020)
				throw 3;
		}
		catch (int i)
		{
			std::cout << "\u001B[31mWarning:\n" << i;
		}
		archives[i].setDay(d1);
		archives[i].setMonth(m1);
		archives[i].setYear(y1);
		for (int j = 0; j < s2; ++j)
		{
			std::cout << "\u001B[0mDocument #" << j + 1 << ":\n";
			std::cout << "\u001B[33mEnter name of author: \u001B[0m";
			cin >> name;
			std::cout << "\u001B[33mEnter surname of author: \u001B[0m";
			cin >> surname;
			std::cout << "\u001B[33mEnter day of birth: \u001B[0m";
			cin >> d1;
			std::cout << "\u001B[33mEnter month of birth: \u001B[0m";
			cin >> m1; 
			std::cout << "\u001B[33mEnter year of birth: \u001B[0m";
			cin >> y1;
			std::cout << "\u001B[33mEnter name of file: \u001B[0m";
			cin >> nameOfFile;
			std::cout << "\u001B[33mEnter extension of file: \u001B[0m";
			cin >> extension;
			std::cout << "\u001B[33mEnter keyword: \u001B[0m";
			cin >> keyword;
			std::cout << "\u001B[33mEnter placing: \u001B[0m";
			cin >> placing;
			std::cout << "\u001B[33mEnter degree of archiving: \u001B[0m";
			cin >> archivingDegree;
			std::cout << "\u001B[33mEnter size: \u001B[0m";
			cin >> size;
			std::cout << "\u001B[33mEnter day of creation: \u001B[0m";
			cin >> d2;
			std::cout << "\u001B[33mEnter month of creation: \u001B[0m";
			cin >> m2;
			std::cout << "\u001B[33mEnter year of creation: \u001B[0m";
			cin >> y2;
			try
			{
				if (name.length() < 2)
					throw 1;
				if (surname.length() < 2)
					throw 2;
				if (d1 < 1 || d1 > 31)
					throw 3;
				if (m1 < 1 || m1 > 12)
					throw 4;
				if (y1 < 1900 || y1 > 2020)
					throw 5;
				if (nameOfFile.length() < 2)
					throw 6;
				if (extension.length() < 2)
					throw 7;
				if (keyword.length() < 2)
					throw 8;
				if (placing.length() < 2)
					throw 9;
				if (size < 1)
					throw  10;
				if (d2 < 1 || d2 > 31)
					throw 11;
				if (m2 < 1 || m2 > 12)
					throw 12;
				if (y2 < 1900 || y2 > 2020)
					throw 13;
			}
			catch (int i)
			{
				std::cout << "\u001B[31mWarning:\n" << i;
			}
			arrayAuthors[i].setName(name);
			arrayAuthors[i].setSurname(surname);
			arrayAuthors[i].setDay(d1);
			arrayAuthors[i].setMonth(m1);
			arrayAuthors[i].setYear(y1);
			arrayFiles[i].setNameOfFile(nameOfFile);
			arrayFiles[i].setExtension(extension);
			arrayDocuments[i][j].setKeywords(keyword);
			arrayDocuments[i][j].setPlacing(placing);
			arrayDocuments[i][j].setArchivingDegree(archivingDegree);
			arrayFiles[i].setSize(size);
			arrayFiles[i].setDay(d2);
			arrayFiles[i].setMonth(m2);
			arrayFiles[i].setYear(y2);
			arrayDocuments[i][j].setFile(&arrayFiles[i]);
			arrayDocuments[i][j].setAuthor(&arrayAuthors[i]);
			allSize = arrayFiles[i] + allSize;
		}
		archives[i].setDocuments(arrayDocuments[i], s2);
	}
	catalog.setElements(archives, s1);
	AverageQuantityDocuments(archives, s1);
	AverageArchiving(&catalog);
	cout << "\n\u001B[32mSize of all files: \u001B[0m" << allSize << endl;
	Table();
	catalog.Show();
	return catalog;
}

CatalogComposition search(bool txt, CatalogComposition catalog, File* arrayFiles, Person* arrayAuthors, TextDocument** arrayDocuments, ArchiveElement* archives)
{
	string line;
	std::string name, surname, nameOfFile, extension, keyword, placing, size, d1, d2, m1, m2, y1, y2, archivingDegree;
	int sizeArray;
	int allSize = 0;
	string file;
	int f;
	cout << "Want to use the default file?\n1 - Yes\n2 - No\n";
	cin >> f;
	if (f == 1)
	{
		if (txt == 1)
		{
			file = "C:\\OOP.txt";
		}
		else
		{
			file = "C:\\OOP.bin";
		}
	}
	else
	{
		cout << "Print name of file for writing: ";
		cin >> file;
	}
	ifstream in(file);
	if (in.is_open())
	{
		getline(in, line);
	}
	sizeArray = stoi(line);
	int x;
	if (in.is_open())
	{
		arrayFiles = new File[sizeArray];
		arrayAuthors = new Person[sizeArray];
		arrayDocuments = new TextDocument * [sizeArray];
		archives = new ArchiveElement[sizeArray];
		std::cout << "Number of archive elements: " << sizeArray << endl;
		for (int i = 0; i < sizeArray; ++i)
		{
			in >> x >> d1 >> m1 >> y1;//читаем кол-во доков в і-ом архиве
			archives[i].setDay(stoi(d1));
			archives[i].setMonth(stoi(m1));
			archives[i].setYear(stoi(y1));
			arrayDocuments[i] = new TextDocument[i+1];
			try
			{
				if (stoi(d1) < 1 || stoi(d1) > 31)
					throw 1;
				if (stoi(m1) < 1 || stoi(m1) > 12)
					throw 2;
				if (stoi(y1) < 1900 || stoi(y1) > 2020)
					throw 3;
			}
			catch (int i)
			{
				std::cout << "\u001B[31mWarning:\n" << i;
			}
			std::cout << "\n\u001B[0mArhieve #" << i + 1 << ":\n";
			for (int j = 0; j < x; ++j)
			{
				std::cout << "\u001B[0mDocument #" << j + 1 << " readed.\n";
				archives[i].setQuantity(i+1);
				in >> name >> surname >> d1 >> m1 >> y1 >> nameOfFile >> extension >> keyword >> placing >> archivingDegree >> size >> d2 >> m2 >> y2;
				try
				{
					if (name.length() < 2)
						throw 1;
					if (surname.length() < 2)
						throw 2;
					if (stoi(d1) < 1 || stoi(d1) > 31)
						throw 3;
					if (stoi(m1) < 1 || stoi(m1) > 12)
						throw 4;
					if (stoi(y1) < 1900 || stoi(y1) > 2020)
						throw 5;
					if (nameOfFile.length() < 2)
						throw 6;
					if (extension.length() < 2)
						throw 7;
					if (keyword.length() < 2)
						throw 8;
					if (placing.length() < 2)
						throw 9;
					if (stoi(size) < 0)
						throw  10;
					if (stoi(d2) < 1 || stoi(d2) > 31)
						throw 11;
					if (stoi(m2) < 1 || stoi(m2) > 12)
						throw 12;
					if (stoi(y2) < 1900 || stoi(y2) > 2020)
						throw 13;
				}
				catch (int i)
				{
					std::cout << "\u001B[31mWarning:\n" << i;
				}
				arrayAuthors[i].setName(name);
				arrayAuthors[i].setSurname(surname);
				arrayAuthors[i].setDay(stoi(d1));
				arrayAuthors[i].setMonth(stoi(m1));
				arrayAuthors[i].setYear(stoi(y1));
				arrayFiles[i].setNameOfFile(nameOfFile);
				arrayFiles[i].setExtension(extension);
				arrayDocuments[i][j].setKeywords(keyword);
				arrayDocuments[i][j].setPlacing(placing);
				arrayFiles[i].setSize(stoi(size));
				arrayFiles[i].setDay(stoi(d2));
				arrayFiles[i].setMonth(stoi(m2));
				arrayFiles[i].setYear(stoi(y2));
				arrayDocuments[i][j].setFile(&arrayFiles[i]);
				arrayDocuments[i][j].setAuthor(&arrayAuthors[i]);
				arrayDocuments[i][j].setArchivingDegree(stoi(archivingDegree));
				allSize = arrayFiles[i] + allSize;
			}
			archives[i].setDocuments(arrayDocuments[i], 1);
		}
		//ArchiveElement* archives = new ArchiveElement[sizeArray];
		//std::cout << sizeArray << endl;
		//CatalogComposition catalog(archives, sizeArray);
		catalog.setElements(archives, sizeArray);
		Table();
		catalog.Show();
		AverageQuantityDocuments(archives, sizeArray);
		AverageArchiving(&catalog);
		cout << "\n\u001B[32mSize of all files: \u001B[0m" << allSize << endl;
		/*for (int i = 0; i < sizeArray; i++)
		{
			delete[] arrayDocuments[i];
		}*/
	}
	in.close();
	/*delete[] arrayFiles;
	delete[] arrayAuthors;
	delete[] arrayDocuments;
	delete[] archives;*/
	return catalog;
}

void write(CatalogComposition *catalog)
{
	string file;
	int f;
	cout << "Want to use the default file?\n1 - Yes\n2 - No\n";
	cin >> f;
	if (f == 1)
	{
		cout << "Want to write to text or binary file?\n1 - Text\n2- Binary\n";
		cin >> f;
		if (f == 1)
		{
			file = "C:\\OOP.txt";
		}
		else
		{
			file = "C:\\OOP.bin";
		}
	}
	else
	{
		cout << "Print name of file for writing: ";
		cin >> file;
	}
	ofstream fout;
	fout.open(file);
	if (fout.is_open())
	{
		fout << catalog->getQuality() << endl;//выводим к-во архивов
		for (int i = 0; i < catalog->getQuality(); ++i)
		{
			fout << catalog->getElement()[i].getQuantity() << " "
				<< catalog->getElement()[i].getDay() << " "
				<< catalog->getElement()[i].getMonth() << " "
				<< catalog->getElement()[i].getYear() << endl;//выводим количество доков в і-том архиве
			for (int j = 0; j < catalog->getElement()[i].getQuantity(); ++j)
			{
				fout << catalog->getElement()[i].getDocument()[j].getPerson()->getName() << " "
					<< catalog->getElement()[i].getDocument()[j].getPerson()->getSurname() << " "
					<< catalog->getElement()[i].getDocument()[j].getPerson()->getDay() << " "
					<< catalog->getElement()[i].getDocument()[j].getPerson()->getMonth() << " "
					<< catalog->getElement()[i].getDocument()[j].getPerson()->getYear() << " "
					<< catalog->getElement()[i].getDocument()[j].getFile()->getNameOfFile() << " "
					<< catalog->getElement()[i].getDocument()[j].getFile()->getExtension() << " "
					<< catalog->getElement()[i].getDocument()[j].getKeywords() << " "
					<< catalog->getElement()[i].getDocument()[j].getPlacing() << " "
					<< catalog->getElement()[i].getDocument()[j].getArchivingDegree() << " "
					<< catalog->getElement()[i].getDocument()[j].getFile()->getSize() << " "
					<< catalog->getElement()[i].getDocument()[j].getFile()->getDay() << " "
					<< catalog->getElement()[i].getDocument()[j].getFile()->getMonth() << " "
					<< catalog->getElement()[i].getDocument()[j].getFile()->getYear() << "\n";
			}
		}
	}
	fout.close();
}

void findText(CatalogComposition* catalog)
{
	string line;
	bool found = false;
	cout << "Enter the name of the file you are looking for\n";
	cin >> line;
	for (int i = 0; i < catalog->getQuality(); ++i)
	{
		for (int j = 0; j < catalog->getElement()[i].getQuantity(); j++)
		{
			if (line == catalog->getElement()[i].getDocument()[j].getFile()->getNameOfFile())
			{
				cout << "File with this name is in archive #" << i+1 << "; document #"  <<j+1<< endl;
				found = true;
			}
		}
	}
	if (!found)
	{
		cout << "There is no file with this name in catalog" << endl;
	}
}

void findNumber(CatalogComposition* catalog)
{
	int line;
	bool found = false;
	cout << "Enter the size of the file you are looking for\n";
	cin >> line;
	for (int i = 0; i < catalog->getQuality(); ++i)
	{
		for (int j = 0; j < catalog->getElement()[i].getQuantity(); j++)
		{
			if (line == catalog->getElement()[i].getDocument()[j].getFile()->getSize())
			{
				cout << "File with this size is in archive #" << i + 1 << "; document #" << j + 1 << endl;
				found = true;
			}
		}
	}
	if (!found)
	{
		cout << "There is no file with this size in catalog" << endl;
	}
}

template <typename M>
void swap(M* n, M* m)
{
	//int n, m;
	
	M* tempor = nullptr;
	tempor = m;
	m = n;
	n = tempor;
	delete[] tempor;
}

void Table()
{
	std::cout << "\n\u001B[32mName:\tSurname:\tFile name:\tExtension:\tSize:\tPlacing:\u001B[0m\n";
}

int operator+(File &T, int size)
{
	size += T.getSize();
	return size;
}

template<typename T>
void AverageQuantityDocuments(T* x, int y)
{
	int av = 0;
	for (int i = 0; i < y; ++i)
	{
		av += x[i].getQuantity();
	}
	cout << "\n\u001B[32mAverage quantity of documents in archeve: \u001B[0m" << av / y;
}

template<typename K>
void AverageArchiving(K* x)
{
	int av = 0, number = 0;
	for (int i = 0; i < x->getQuality(); ++i)
	{
		for (int j = 0; j < x->getElement()[i].getQuantity(); ++j)
		{
			av += x->getElement()[i].getDocument()[j].getArchivingDegree();
			number++;
		}
	}
	cout << "\n\u001B[32mAverage quantity of archiving files: \u001B[0m" << av / number;
}

void write(CatalogComposition catal, bool txt)
{
	string file;
	if (txt)
	{
		file = "C:\\Kurs.txt";
	}
	else
	{
		file = "C:\\Kurs.bin";
	}
	ofstream fout;
	fout.open(file);
	if (!fout.is_open())
	{
		cout << "Error: cann't open file!";
	}
	else
	{
		/*int k = catal->getQuality();
		for (int i = 0; i < k; i++)
		{
			fout.write((char*)&catal[i], sizeof(catal[i]));
		}*/
		//fout.write((char*)&catal, sizeof(CatalogComposition));
		//fout << catal;
		//catal.write(fout);
		fout.write(reinterpret_cast<char*>(&catal), sizeof(catal));
	}
	fout.close();
}