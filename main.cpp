#include <QtGui>
#include <string> 
#include <QtWidgets/QApplication>
#include <QPushButton>

int i, j;

int main(int argv, char **args)
{
	QApplication app(argv, args);
	int n = 8;
	int size = 40;
	int bsize = (n*size - 5)/3 - 5;
	QPushButton *buttons[n][n];

	QWidget window;
	window.setGeometry(300, 300, 10+size*n, 5+size*n + size + 10);
	window.setFixedSize(window.size());
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			buttons[i][j] = new QPushButton("", &window);
			QObject::connect(buttons[i][j], SIGNAL(clicked()), qApp, SLOT(quit()));
			buttons[i][j]->setGeometry(5+i*size, 5+j*size, size, size);
		}
	}
	QPushButton *newGameButton = new QPushButton("New Game", &window);
	newGameButton->setGeometry(5, n*size + 10, bsize, size);

	QPushButton *diffButton = new QPushButton("Difficulty", &window);
	diffButton->setGeometry(5 + 2*n*size/3 + 5, n*size + 10, bsize, size);

	window.show();
	return app.exec();
}
