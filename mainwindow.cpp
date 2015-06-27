#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //srand(time(null));
    for(int i=0; i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            b[i][j]=new Block(this,i,j);
            connect(b[i][j],SIGNAL(Click(int,int)),this,SLOT(button_clicked(int,int)));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GameStart()
{
    isClicked=false;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            b[i][j]->setRandomNumber();
            b[i][j]->setButtonPicture();
            if(j>=2&&b[i][j]->number==b[i][j-1]->number && b[i][j]->number==b[i][j-2]->number)
            {
                j--;
            }
            if(i>=2&&b[i][j]->number==b[i-1][j]->number && b[i][j]->number==b[i-2][j]->number)
            {
                j--;
            }
        }
    }
}

void MainWindow::setClickedPicture(Block *a)
{
    if(!isClicked)
    {
        switch(a->number)
        {
        case 1:
            a->button->setIcon(QIcon(QPixmap(":/bg/red_clicked.png")));
            break;
        case 11:
            a->button->setIcon(QIcon(QPixmap(":/bg/red_vertical_bomb_clicked.png")));
            break;
        case 12:
            a->button->setIcon(QIcon(QPixmap(":/bg/red_horizontal_bomb_clicked.png")));
            break;
        case 13:
            a->button->setIcon(QIcon(QPixmap(":/bg/red_bomb_clicked.png")));
            break;
        case 2:
            a->button->setIcon(QIcon(QPixmap(":/bg/yellow_clicked.png")));
            break;
        case 21:
            a->button->setIcon(QIcon(QPixmap(":/bg/yellow_vertical_clicked.png")));
            break;
        case 22:
            a->button->setIcon(QIcon(QPixmap(":/bg/yellow_horizontal_bomb_clicked.png")));
            break;
        case 23:
            a->button->setIcon(QIcon(QPixmap(":/bg/yellow_bomb_clicked.png")));
            break;
        case 3:
            a->button->setIcon(QIcon(QPixmap(":/bg/green_clicked.png")));
            break;
        case 31:
            a->button->setIcon(QIcon(QPixmap(":/bg/green_vertical_bomb_clicked.png")));
            break;
        case 32:
            a->button->setIcon(QIcon(QPixmap(":/bg/green_horizontal_bomb_clicked.png")));
            break;
        case 33:
            a->button->setIcon(QIcon(QPixmap(":/bg/green_bomb_clicked.png")));
            break;
        case 4:
            a->button->setIcon(QIcon(QPixmap(":/bg/blue_clicked.png")));
            break;
        case 41:
            a->button->setIcon(QIcon(QPixmap(":/bg/blue_vertical_bomb_clicked.png")));
            break;
        case 42:
            a->button->setIcon(QIcon(QPixmap(":/bg/blue_horizontal_bomb_clicked.png")));
            break;
        case 43:
            a->button->setIcon(QIcon(QPixmap(":/bg/blue_bomb_clicked.png")));
            break;
        case 5:
            a->button->setIcon(QIcon(QPixmap(":/bg/power_bomb_clicked.png")));
            break;
        }
    }
    else{
        a->setButtonPicture();
    }
}

bool MainWindow::Judge(int row1, int col1, int row2, int col2)
{
    JudgeStar(row1,col1);
    JudgeStar(row2,col2);
    Judge9(row1,col1);
    Judge9(row2,col2);
    JudgeHor(row1,col1);
    JudgeHor(row2,col2);
    JudgeVer(row1,col1);
    JudgeVer(row2,col2);
    RenewPicture();
}

bool MainWindow::JudgeStar(int R, int C)
{
    int return_value;
    bool anySpam= false;
    destroy=new Star;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1:
            destroy->spam(b,b[R][C],1);
            anySpam=true;
            break;
        case 2:
            destroy->spam(b,b[R][C],2);
            anySpam=true;
            break;
        case 3:
            destroy->spam(b,b[R][C],3);
            anySpam=true;
            break;
        case 4:
            destroy->spam(b,b[R][C],4);
            anySpam=true;
            break;
        }
        delete destroy;
        return anySpam;
    }
}

bool MainWindow::Judge9(int R, int C)
{
    int return_value;
    int anySpam=false;
    destroy=new NineBlock;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1:
            destroy->spam(b,b[R][C],1);
            anySpam=true;
            break;
        case 2:
            destroy->spam(b,b[R][C],2);
            anySpam=true;
            break;
        case 3:
            destroy->spam(b,b[R][C],3);
            anySpam=true;
            break;
        case 4:
            destroy->spam(b,b[R][C],4);
            anySpam=true;
            break;
        }
        delete destroy;
        return anySpam;
    }
}

bool MainWindow::JudgeHor(int R, int C)
{
    int return_value;
    bool anySpam= false;
    destroy=new Horizontal;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1:
            destroy->spam(b,b[R][C],1);
            anySpam=true;
            break;
        case 2:
            destroy->spam(b,b[R][C],2);
            anySpam=true;
            break;
        case 3:
            destroy->spam(b,b[R][C],3);
            anySpam=true;
            break;
        case 4:
            destroy->spam(b,b[R][C],4);
            anySpam=true;
            break;
        }
        delete destroy;
        return anySpam;
    }
}

bool MainWindow::JudgeVer(int R, int C)
{
    int return_value;
    bool anySpam= false;
    destroy=new Vertical;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value)
    {
        switch(return_value)
        {
        case 1:
            destroy->spam(b,b[R][C],1);
            anySpam=true;
            break;
        case 2:
            destroy->spam(b,b[R][C],2);
            anySpam=true;
            break;
        case 3:
            destroy->spam(b,b[R][C],3);
            anySpam=true;
            break;
        case 4:
            destroy->spam(b,b[R][C],4);
            anySpam=true;
            break;
        }
        delete destroy;
        return anySpam;
    }
}

void MainWindow::RenewPicture()
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            b[i][j]->setButtonPicture();
}

void MainWindow::button_clicked(int R, int C)
{
    if(!isClicked)//just clicked
    {
        setClickedPicture(b[R][C]);
        record_R=R;
        record_C=C;
        isClicked=true;
    }
    else{
        if(record_R==R && record_C==C-1)//change the icon to the left
        {
            *b[record_R][record_C]-b[R][C];
            if(!Judge(record_R,record_C,R,C))
            {

            }
        }
        else if(record_R==R && record_C==C+1)//to the right
        {
            *b[R][C]-b[record_R][record_C];
            if(!Judge(record_R,record_C,R,C))
            {

            }
        }
        else if(record_C==C && record_R==R-1)
        {
            *b[record_R][record_C]|b[R][C];
            if(!Judge(record_R,record_C,R,C))
            {

            }
        }
        else if(record_C==C && record_R==R+1)
        {
            *b[R][C]|b[record_R][record_C];
            if(!Judge(record_R,record_C,R,C))
            {

            }
        }
        else{
            setClickedPicture(b[record_R][record_C]);
        }
        isClicked=false;
    }
}

