#pragma once
#include <AIS_Point.hxx>
#include <AIS_InteractiveContext.hxx>
#include <gp_Pnt.hxx>
#include <Quantity_Color.hxx>
#include <Standard_Boolean.hxx>
#include <Geom_CartesianPoint.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <TopoDS_Face.hxx>
#include <Handle_Geom_BSplineCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Precision.hxx>
#include <Standard_Boolean.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>


class DrawUtil
{
public:
	DrawUtil(void);
	~DrawUtil(void);

	static Handle_AIS_Point DrawVertex(Handle_AIS_InteractiveContext myAISContext,
									const gp_Pnt& aPnt,
                                   const Quantity_Color& theColor,
                                   const Standard_Boolean toDisplay)
	{
		Handle(AIS_Point) aGraphicPoint = new AIS_Point (new Geom_CartesianPoint(aPnt));

		myAISContext->SetColor (aGraphicPoint, theColor, toDisplay);
		if (toDisplay)
		{
			myAISContext->Display (aGraphicPoint);
		//COCCDemoDoc::Fit();
		}

		return aGraphicPoint;
	};

	//static Handle_AIS_Shape DrawSurface( Handle_AIS_InteractiveContext myAISContext,
	//											const Handle_Geom_BSplineCurve &surf,
	//											const Quantity_Color& theColor,
	//											const Standard_Boolean toDisplay)
	//{
	//	Standard_Real precision = Precision::Confusion();
	//	TopoDS_Face topoface = BRepBuilderAPI_MakeFace(surf,precision);
	//	Handle(AIS_Shape) surf_ais = new AIS_Shape(topoface);
	//	myAISContext->SetMaterial(surf_ais,Graphic3d_NOM_PLASTIC,Standard_True);    
	//	myAISContext->SetColor(surf_ais,theColor,Standard_True); 	
	//	myAISContext->Display(surf_ais,Standard_False);

	//	return surf_ais;
	//};



	static Handle_AIS_Shape DrawCurve( Handle_AIS_InteractiveContext myAISContext,
												const Handle_Geom_BSplineCurve &surf,
												const Quantity_Color& theColor,
												const Standard_Boolean toDisplay)
	{
		Standard_Real precision = Precision::Confusion();
		TopoDS_Edge topoface = BRepBuilderAPI_MakeEdge(surf);
		Handle(AIS_Shape) surf_ais = new AIS_Shape(topoface);
		myAISContext->SetMaterial(surf_ais,Graphic3d_NOM_PLASTIC,Standard_True);    
		myAISContext->SetColor(surf_ais,theColor,Standard_True); 	
		myAISContext->Display(surf_ais,Standard_False);

		return surf_ais;
	};

};

