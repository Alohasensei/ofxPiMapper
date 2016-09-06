#include "SurfaceHighlightWidget.h"

namespace ofx {
namespace piMapper {

SurfaceHighlightWidget::SurfaceHighlightWidget(){
	_sm = 0;
}

void SurfaceHighlightWidget::draw(){
	if(_sm == 0){
		return;
	}
	
	if(_sm->getSelectedSurface() == 0){
		return;
	}
	
	if(_sm->getSelectedSurface()->getType() == SurfaceType::QUAD_SURFACE &&
		((QuadSurface *)_sm->getSelectedSurface())->getPerspectiveWarping()){
		ofPolyline line = _sm->getSelectedSurface()->getHitArea();
		ofPushStyle();
		ofSetLineWidth(1);
		ofSetColor(255, 255, 255, 255);
		line.draw();
		ofPopStyle();
	}else if(_sm->getSelectedSurface()->getType() == SurfaceType::GRID_WARP_SURFACE){
		_sm->getSelectedSurface()->getMesh().drawWireframe();
	}else{
		ofPolyline p;
		for(unsigned int i = 0;
			i < _sm->getSelectedSurface()->getMesh().getVertices().size();
			++i){
			
			p.addVertex(ofPoint(
				_sm->getSelectedSurface()->getMesh().getVertices()[i]));
		}
		p.close();
		p.draw();
	}
}

} // namespace piMapper
} // namespace ofx
