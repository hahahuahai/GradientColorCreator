#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<double> RGBdata;//存储渐变色RGB值


void gradientcolorcreator(const unsigned int r_start, const unsigned int g_start, const unsigned int b_start, const unsigned int r_end, const unsigned int g_end, const unsigned int b_end, const int width, const int height)
{
	double r_difference = (double)(r_end - r_start) / (double)(width*height);//两个颜色的差值
	double g_difference = (double)(g_end - g_start) / (double)(width*height);
	double b_difference = (double)(b_end - b_start) / (double)(width*height);
	double r = 0.0, g = 0.0, b = 0.0;
	for (int i = 0; i < width*height; i++)
	{
		//计算当前位置的RGB分量
		r = r_start + i * r_difference;
		g = g_start + i * g_difference;
		b = b_start + i * b_difference;
		RGBdata.push_back(r);
		RGBdata.push_back(g);
		RGBdata.push_back(b);
	}
	cout << "渐变色生成成功！" << endl;
}

//将渐变色的RGB值输出至txt文件
void toTXT(string outputPath)
{
	ofstream outfile(outputPath, ios::out);
	for each (double data in RGBdata)
	{
		outfile << data << "," << endl;
	}
	cout << "txt生成成功！" << endl;
}

int main()
{
	gradientcolorcreator(0, 0, 0, 255, 255, 255, 1000, 800);
	toTXT("gradientcolorcreator.txt");
	return 0;
}