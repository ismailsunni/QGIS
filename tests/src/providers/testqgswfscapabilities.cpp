/***************************************************************************
    testqgswfscapabilities.cpp
    ---------------------
    begin                : May 2020
    copyright            : (C) 2020 by Ismail Sunni
    email                : ismail dot sunni at camptocamp dot com
 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include <QFile>
#include <QObject>
#include "qgstest.h"
#include "qgswfscapabilities.h"
#include <qgsapplication.h>


/**
 * \ingroup UnitTests
 * This is a unit test for the WFS capabilities parser.
 */
class TestQgsWfsCapabilities: public QObject
{
    Q_OBJECT
  private slots:

    void initTestCase()
    {
      // init QGIS's paths - true means that all path will be inited from prefix
      QgsApplication::init();
      QgsApplication::initQgis();
    }

    //runs after all tests
    void cleanupTestCase()
    {
      QgsApplication::exitQgis();
    }


    void read()
    {
      QgsWfsCapabilities capabilities( "http://localhost:8380/?SERVICE=WFS&REQUEST=GetCapabilities" );

      QFile file( QStringLiteral( TEST_DATA_DIR ) + "/provider/GetCapabilities.xml" );
      QVERIFY( file.open( QIODevice::ReadOnly | QIODevice::Text ) );
      const QByteArray content = file.readAll();
      QVERIFY( content.size() > 0 );
//      const QgsWmsParserSettings config;

//      QVERIFY( capabilities.parseResponse( content, config ) );
//      QCOMPARE( capabilities.supportedLayers().size(), 5 );
//      QCOMPARE( capabilities.supportedLayers()[0].name, QString( "agri_zones" ) );
//      QCOMPARE( capabilities.supportedLayers()[1].name, QString( "buildings" ) );
//      QCOMPARE( capabilities.supportedLayers()[2].name, QString( "land_surveing_parcels" ) );
//      QCOMPARE( capabilities.supportedLayers()[3].name, QString( "cadastre" ) );
//      QCOMPARE( capabilities.supportedLayers()[4].name, QString( "test" ) );

//      // make sure the default style is not seen twice in the child layers
//      QCOMPARE( capabilities.supportedLayers()[3].style.size(), 1 );
//      QCOMPARE( capabilities.supportedLayers()[3].style[0].name, QString( "default" ) );
//      QCOMPARE( capabilities.supportedLayers()[1].style.size(), 1 );
//      QCOMPARE( capabilities.supportedLayers()[1].style[0].name, QString( "default" ) );
//      QCOMPARE( capabilities.supportedLayers()[2].style.size(), 1 );
//      QCOMPARE( capabilities.supportedLayers()[2].style[0].name, QString( "default" ) );

//      // check it can read 2 styles for a layer and that the legend URL is OK
//      QCOMPARE( capabilities.supportedLayers()[0].style.size(), 2 );
//      QCOMPARE( capabilities.supportedLayers()[0].style[0].name, QString( "yt_style" ) );
//      QCOMPARE( capabilities.supportedLayers()[0].style[0].legendUrl.size(), 1 );
//      QCOMPARE( capabilities.supportedLayers()[0].style[0].legendUrl[0].onlineResource.xlinkHref,
//                QString( "http://www.example.com/yt.png" ) );
//      QCOMPARE( capabilities.supportedLayers()[0].style[1].name, QString( "fb_style" ) );
//      QCOMPARE( capabilities.supportedLayers()[0].style[1].legendUrl.size(), 1 );
//      QCOMPARE( capabilities.supportedLayers()[0].style[1].legendUrl[0].onlineResource.xlinkHref,
//                QString( "http://www.example.com/fb.png" ) );
    }

//    void wmst11extent()
//    {
//      // test parsing WMS1.1 temporal extent
//      const QString layer = R"""(<Layer queryable="0" opaque="0" cascaded="0">
//                            <Name>danger_index</Name>
//                            <Title>danger_index</Title>
//                            <SRS>EPSG:4326</SRS>
//                            <LatLonBoundingBox minx="-180" miny="-90" maxx="180" maxy="90" />
//                            <BoundingBox SRS="EPSG:4326"
//                                        minx="-180" miny="-90" maxx="180" maxy="90" />
//                            <Dimension name="time" units="ISO8601"/>
//                            <Extent name="time" default="2019-01-01" nearestValue="0">2018-01-01/2019-12-31</Extent>
//                        </Layer>)""";

//      QDomDocument doc;
//      doc.setContent( layer );
//      QgsWmsCapabilities cap;
//      QgsWmsLayerProperty prop;
//      cap.parseLayer( doc.documentElement(), prop );

//      QCOMPARE( prop.name, QStringLiteral( "danger_index" ) );
//      QCOMPARE( prop.dimensions.size(), 1 );
//      QCOMPARE( prop.dimensions.at( 0 ).name, QStringLiteral( "time" ) );
//      QCOMPARE( prop.dimensions.at( 0 ).defaultValue, QStringLiteral( "2019-01-01" ) );
//      QCOMPARE( prop.dimensions.at( 0 ).extent, QStringLiteral( "2018-01-01/2019-12-31" ) );
//      QCOMPARE( prop.dimensions.at( 0 ).units, QStringLiteral( "ISO8601" ) );
//    }
};

QGSTEST_MAIN( TestQgsWfsCapabilities )
#include "testqgswfscapabilities.moc"
