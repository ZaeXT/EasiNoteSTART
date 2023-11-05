#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
int gen_rnd(int gen_min = 0,int gen_max = 36)
int main()
{
#ifdef _WIN32   
    system("chcp 65001");
    system("cls");
#endif
    string cfg[2],cho;
    cho = gen_rnd();
    fstream fs("config.ini", ios::in);
    if (fs.is_open())
    {
        for (int i = 0; i < 2; i++)
        {
            getline(fs, cfg[i]);
            if (i == 0)
            {
                cfg[i].erase(0, 8);
            }
            else
            {
                cfg[i].erase(0, 11);
            }
        }
    }
    else
    {
        cout << "第一次使用，开始初始化。。。\n";
        ofstream createCfg("config.ini");
        if (createCfg.is_open())
        {
            string appD,splashD;
            cout << "请输入希沃白板程序路径：\n";
            cin >> appD;
            createCfg << "AppPath=" << appD << endl;
            cout << "Done!\n请输入SplashScreen.png文件夹路径：\n";
            cin >> splashD;
            createCfg << "SplashPath=" << splashD << endl;
            createCfg.close();
            cout << "Done!\n";
            while (true)
            {
            cout<<"初始化成功！\n请重新启动！\n ";
            }
        }
        else
        {
            cerr << "初始化失败！\n";
        }
    }
    filesystem::rename(cfg[1] + "SplashScreen.png", cfg[1] + "Original.png");
    filesystem::copy(cho + ".png", cfg[1] + "SplashScreen.png");

    return 0;
}