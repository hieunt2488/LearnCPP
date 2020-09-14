//http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm

#include <iostream>
#include <fstream>

uint16_t twoBytesToWord(char byteOne, char byteTwo)
{
	uint16_t result{};

	return result = byteOne | byteTwo << 8;
}

uint32_t fourBytesToDword(unsigned char byteOne, unsigned char byteTwo, unsigned char byteThree, unsigned char byteFour)
{
	uint32_t result = (uint32_t)byteOne | (uint32_t)byteTwo << 8 | (uint32_t)byteThree << 16 | (uint32_t)byteFour << 32;

	return result;
}


int readBitmapFileHeader()
{
	// Read the header of a bitmap file called SampleBitmap.bmp
	// The header of a bitmap file have 14 bytes
	// The Structure of the header:
	// File Type: 2 byte (must be BM)
	// File Size: 4 bytes 
	// Reserve 1: 4 bytes (not used)
	// Reserve 2: 4 bytes (not used)
	// File Offset to PixelArray: 8 bytes (The beginning of the Pixel array)

	uint16_t fileType;
	uint32_t fileSize;


	// ifstream is used for reading the file

	std::ifstream inf{ "2.bmp", std::ios::binary };

	// if couldn't open the file
	if (!inf)
	{
		std::cerr << "Couldn't open the file" << std::endl;
		return 1;
	}

	// define 14 bytes array to store the header

	unsigned char bmpHeader[14];

	for (int i = 0; i < 14; i++)
	{
		// read one byte of the header of the bitmap picture to bmpHeader array
		inf.read((char *)bmpHeader + i, 1);
	}

	// using ofstream for writting to file
	// 

	std::ofstream outf{ "BitmapInfo.txt", std::ios::binary };

	if (!outf)
	{
		std::cerr << "Couldn't open file to write" << std::endl;
		return 1;
	}

	for (int i = 0; i < 14; i++)
	{
		outf.write((char *)bmpHeader + i, 1);
	}

	uint32_t tmp = fourBytesToDword(bmpHeader[2], bmpHeader[3], bmpHeader[4], bmpHeader[5]);

	std::cout << "File Size: " << tmp << " Bytes \n";



	return 0;

}

int readBitmapFileHeaderTmp()
{
	// use file stream to read files

	std::ifstream inf{ "SampleBitmap.bmp", std::ios::binary };

	if (!inf)
	{
		std::cerr << "Couldn't open file";
		return 1;
	}

	char * bmHeader = new char[14];

	for (int i = 0; i < 14; i++)
	{
		inf.read(bmHeader + i, 1);
	}

	char tmp = bmHeader[0];

	char tmp2 = bmHeader[1];

	char tmp3 = bmHeader[2];

	char tmp4 = bmHeader[3];




	std::cout << "Size of the file: " << (int)(unsigned char)tmp3;





	return 0;
}

int readBitmapFileDataOffset()
{
	// Read the header of a bitmap file called SampleBitmap.bmp
	// The header of a bitmap file have 14 bytes
	// The Structure of the header:
	// File Type: 2 byte (must be BM)
	// File Size: 4 bytes 
	// Reserve 1: 2 bytes (not used)
	// Reserve 2: 2 bytes (not used)
	// File Offset to PixelArray: 4 bytes (The beginning of the Pixel array)

	uint16_t fileType;
	uint32_t fileSize;


	// ifstream is used for reading the file

	std::ifstream inf{ "2.bmp", std::ios::binary };

	// if couldn't open the file
	if (!inf)
	{
		std::cerr << "Couldn't open the file" << std::endl;
		return 1;
	}

	// define 14 bytes array to store the header

	unsigned char bmpHeader[14];

	for (int i = 0; i < 14; i++)
	{
		// read one byte of the header of the bitmap picture to bmpHeader array
		inf.read((char *)bmpHeader + i, 1);
	}

	// using ofstream for writting to file
	// 

	std::ofstream outf{ "BitmapInfo.txt", std::ios::binary };

	if (!outf)
	{
		std::cerr << "Couldn't open file to write" << std::endl;
		return 1;
	}

	for (int i = 0; i < 14; i++)
	{
		outf.write((char *)bmpHeader + i, 1);
	}

	uint32_t tmp = fourBytesToDword(bmpHeader[10], bmpHeader[11], bmpHeader[12], bmpHeader[13]);

	std::cout << "Data Offset: " << tmp << "\n";



	return 0;
}




int main()
{
	readBitmapFileHeader();
	readBitmapFileDataOffset();

	std::cin.clear();  //reset any error flags
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), 'x'); //ignore any characters in the input buffer until we find a 'x' character

	return 0;
}