///
/// pedsim - A microscopic pedestrian simulation system. 
/// Copyright (c) 2003 - 2012 by Christian Gloor
///                              
///
///       _
///   _  (__/   _ _ _   /    _ / _ ' __/'_    _ /    _ 
/// _) ()/ /((/(// (-  ()(/ ( /)/ /_) //(//) (/(()()/  
///                      /                  _/         
///

// ---> export LD_LIBRARY_PATH=libpedsim

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtOpenGL>
#include <QGLWidget>
#include <QGLFormat>
#include <QPen>
#include <QTimer>

#include <iostream>                       // cout
#include <stdlib.h>                       // random

#include "pedsim.h"

#include "mainwindow.h"
#include "agent.h"
#include "obstacle.h"
#include "style.h"
#include "waypoint.h"
#include "scene.h"
#include "config.h"
#include "loadscene.h"

using namespace std;

Config config;


// ----------------------------------------------------
// Name: main
// Description: - 
// Introduced: chgloor Monday, December 29, 2003 10:31:59
// Return value: 0
// ----------------------------------------------------
int main(int argc, char *argv[]) {
	
	QString scenefile = argv[1];
	if (scenefile == "") {
		scenefile = "scene.xml";
	}
	
	Q_INIT_RESOURCE(application);
	
	QApplication app(argc, argv);
	QApplication::setStyle(new Style());

	MainWindow mainwindow;
	mainwindow.show();

QGraphicsScene *graphicsscene = new QGraphicsScene(0);

	graphicsscene->setBackgroundBrush(Qt::black);
	graphicsscene->setItemIndexMethod(QGraphicsScene::NoIndex);

	Scene *pedscene = new Scene(graphicsscene);

	Loadscene l(scenefile, pedscene, graphicsscene);

	mainwindow.graphicsView->setScene(graphicsscene);
	mainwindow.graphicsView->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
	mainwindow.graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
	mainwindow.graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);	
	mainwindow.graphicsView->show();

	return app.exec();
}





