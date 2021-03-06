#pragma once
#include "CurveskelPlugins.h"
#include "CurveskelModel.h"
#include "CurveskelQForEach.h"

class skeleton_resample : public CurveskelFilterPlugin{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "curveskel_filter_resample.plugin.starlab")
    Q_INTERFACES(FilterPlugin)

private:
    CurveskelModel * skel;
    CurveskelModel::Vertex_property<CurveskelTypes::Point> skel_points;

    void recursiveSplitEdge(CurveskelModel::Edge e, double threshold);

public:
    QString name() { return "Skeleton resampler"; }
    QString description() { return "Skeleton resampling by mid-point edge split."; }
	void applyFilter(RichParameterSet*);
    void initParameters(RichParameterSet *parameters);
};
