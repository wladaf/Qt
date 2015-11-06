#include <QtGui>
#include <string> 

int main(int argv, char **args)
{
	int i, j;
	int n = 5;
	int size = 30;
	QApplication app(argv, args);

	QPushButton *buttons[n][n];

	QWidget window;

	window.setGeometry(300, 300, size*n, size*n + size + 10);
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			buttons[i][j] = new QPushButton("", &window);
			QObject::connect(buttons[i][j], SIGNAL(clicked()), qApp, SLOT(quit()));
			buttons[i][j]->setGeometry(i*size, j*size, size, size);
		}
	}
	
	window.show();

	return app.exec();
}