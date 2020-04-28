#include <iostream>
using namespace std;
//递归算法解决八皇后问题。总共有92种解法。
int c[20], n = 8, cnt = 0;
void print()
{

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j == c[i])
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;
}
void search(int r)
{
    if (r == n)
    {
        print();
        ++cnt;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        c[r] = i;
        int ok = 1;
        for (int j = 0; j < r; ++j)
            if (c[r] == c[j] || r - j == c[r] - c[j] || r - j == c[j] - c[r])
            {
                ok = 0;
                break;
            }
        if (ok)
            search(r + 1);
    }
}
int eightQueen()
{
    search(0);
    cout << cnt << endl;
    return 0;
}
// TODO
// FIXME
// tag
// done
// MEMO

int main()
{
    freopen("testData.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    time_t begin, end;
    double ret;
    begin = clock();

    main0();
    //eightQueen();

    end = clock();
    ret = (double)(end - begin) * 1000 / CLOCKS_PER_SEC;
    printf("\n runtime:%f", ret);

    //fclose(fp);
    fclose(stdin);
    fclose(stdout);
}
