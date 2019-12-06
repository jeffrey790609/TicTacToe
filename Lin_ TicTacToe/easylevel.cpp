#include "easylevel.h"
using namespace std;

easylevel::easylevel()
{

}

bool easylevel::is_winning(char ch)
{
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[i][j] == '-' && grid[i][(j + 1) % 3] == ch && grid[i][(j + 2) % 3] == ch) {
                grid[i][j] = 'X';
                push_new_done(i, j);
                return 1;
            }
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[j][i] == '-' && grid[(j + 1) % 3][i] == ch && grid[(j + 2) % 3][i] == ch) {
                grid[j][i] = 'X';
                push_new_done(j, i);
                return 1;
            }
    for (int j = 0;j < 3;j++)
        if (grid[j][j] == '-' && grid[(j + 1) % 3][(j + 1) % 3] == ch && grid[(j + 2) % 3][(j + 2) % 3] == ch) {
            grid[j][j] = 'X';
            push_new_done(j, j);
            return 1;
        }
    for (int j = 0;j < 3;j++)
        if (grid[j][2 - j] == '-' && grid[(j + 1) % 3][2 - (j + 1) % 3] == ch && grid[(j + 2) % 3][2 - (j + 2) % 3] == ch) {
            grid[j][2 - j] = 'X';
            push_new_done(j, 2 - j);
            return 1;
        }
    return 0;
}

void easylevel::random_move()
{
    vector<pair<int, int>> a;
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[i][j] == '-')
                a.push_back({i, j});
    srand(time(NULL));
    int r_indx = rand() % a.size();
    grid[a[r_indx].first][a[r_indx].second] = 'X';
    push_new_done(a[r_indx].first, a[r_indx].second);
}

int easylevel::make_move()
{
    if (is_winning('X'));
    else if(is_winning('O'));
    else {
        random_move();
        return 1;}
}


char easylevel::input(char c)
{
    int pi, xi, yi;
    char ca;
    char in = getch();
    pi = in - 48;
    xi = 2 - (pi - 1) / 3;
    yi = (pi - 1) % 3;
    while ((grid[xi][yi] != '-' || pi < 1 || pi > 9) && in != 'z' && in != 'Z' && in != 'b' && in != 'B' && in != 'r' && in != 'R') {
        cout << "\033[1AWrong input. Try again: ";
        in = getch();
        pi = in - 48;
        xi = 2 - (pi - 1) / 3;
        yi = (pi - 1) % 3;
    }
    if (pi >= 1 && pi <= 9) {
        ca = c;
        grid[xi][yi] = ca;
        push_new_done(xi, yi);
    }
    return in;
}

char c_undo;
void easylevel::undo()
{
    if (st_done.size() > 0) {
        pii a = st_done.back();
        st_done.pop_back();
        c_undo = grid[a.first][a.second];
        grid[a.first][a.second] = '-';
        st_undone.push_back({a, c_undo});
    }
}

void easylevel::redo()
{
    if (st_undone.size() > 0) {
        pair<pii, char> a = st_undone.back();
        st_undone.pop_back();
        grid[a.first.first][a.first.second] = a.second;
        st_done.push_back(a.first);
    }
}

void easylevel::push_new_done(int x, int y)
{
    st_done.push_back({x, y});
    st_undone.clear();
}


void easylevel::do_last_move(char c)
{
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (grid[i][j] == '-') {
                grid[i][j] = c;
                push_new_done(i, j);
                return;
            }
}
