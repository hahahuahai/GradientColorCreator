#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<double> RGBdata;//�洢����ɫRGBֵ


void gradientcolorcreator(const unsigned int r_start, const unsigned int g_start, const unsigned int b_start, const unsigned int r_end, const unsigned int g_end, const unsigned int b_end, const int width, const int height)
{
	double r_difference = (double)(r_end - r_start) / (double)(width*height);//������ɫ�Ĳ�ֵ
	double g_difference = (double)(g_end - g_start) / (double)(width*height);
	double b_difference = (double)(b_end - b_start) / (double)(width*height);
	double r = 0.0, g = 0.0, b = 0.0;
	for (int i = 0; i < width*height; i++)
	{
		//���㵱ǰλ�õ�RGB����
		r = r_start + i * r_difference;
		g = g_start + i * g_difference;
		b = b_start + i * b_difference;
		RGBdata.push_back(r);
		RGBdata.push_back(g);
		RGBdata.push_back(b);
	}
	cout << "����ɫ���ɳɹ���" << endl;
}

//������ɫ��RGBֵ�����txt�ļ�
void toTXT(string outputPath)
{
	ofstream outfile(outputPath, ios::out);
	for each (double data in RGBdata)
	{
		outfile << data << "," << endl;
	}
	cout << "txt���ɳɹ���" << endl;
}

int main()
{
	gradientcolorcreator(0, 0, 0, 255, 255, 255, 1000, 800);
	toTXT("gradientcolorcreator.txt");
	return 0;
}