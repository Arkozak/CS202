#include "svg.hpp"

void svgGraph(CityList& list, CityPath& path, string outputName) {
	double minX = list.minX();
	double maxX = list.maxX();
	double minY = list.minY();
	double maxY = list.maxY();

	string line;

	ofstream svgOut(outputName);
	if (svgOut.is_open())
	{

		line = "<html xmlns=\"http://www.w3.org/1999/xhtml\"\n";
		line = line + "xmlns:svg=\"http://www.w3.org/2000/svg\">\n";
		line = line + "<body>\n <svg:svg width=\"2250px\" height=\"2500px\">\n";
		svgOut << line;

		double x = 0;
		double y = 0;
		double oldX = 0;
		double oldY = 0;
		double startX = 0;
		double startY = 0;
		string dot = "";

		// INSERT CITIES AND LINES HERE
		for (auto i = 0; i < path.size(); i++) {
			oldX = x;
			oldY = y;

			dot = "<svg:circle cx=\"";
			x = 1980 - 1920 * (list.getCityLon(path.getPath(i)) - minX) / (maxX - minX);
			y = 2080 - 1080 * (list.getCityLat(path.getPath(i)) - minY) / (maxY - minY);

			//Cities
			dot = dot + std::to_string(x);
			dot = dot + "\" cy=\"";
			dot = dot + std::to_string(y);
			dot = dot + "\" r=\"";
			dot = dot + '3';
			dot = dot + "\" fill=\"#0078ff\"/>\n";

			if (i == 0) {
				startX = x;
				startY = y;
			}

			//Lines
			if (i != 0)
			{
				dot = dot + "<svg:line x1=\"";
				dot = dot + std::to_string(oldX);
				dot = dot + "\" y1=\"";
				dot = dot + std::to_string(oldY);
				dot = dot + "\" x2=\"";
				dot = dot + std::to_string(x);
				dot = dot + "\" y2=\"";
				dot = dot + std::to_string(y);
				dot = dot + "\" style=\"stroke:rgb(255,0,0);stroke-width:1\" />\n";
			}


			svgOut << dot;
		}

		//Connect last city to first
		dot = "<svg:line x1=\"";
		dot = dot + std::to_string(x);
		dot = dot + "\" y1=\"";
		dot = dot + std::to_string(y);
		dot = dot + "\" x2=\"";
		dot = dot + std::to_string(startX);
		dot = dot + "\" y2=\"";
		dot = dot + std::to_string(startY);
		dot = dot + "\" style=\"stroke:rgb(255,0,0);stroke-width:1\" />\n";


		line = "</svg:svg>\n <svg:svg width=\"2250px\" height=\"2500px\">\n";
		line = dot + "</svg:svg>\n </body>\n </html>";
		svgOut << line;
	}
}