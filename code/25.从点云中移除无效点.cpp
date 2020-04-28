#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/filter.h>

int main(int argc, char **argv)
{
	typedef pcl::PointCloud<pcl::PointXYZ> CloudType;
	CloudType::Ptr cloud(new CloudType);
	cloud->is_dense = false;
	CloudType::Ptr output_cloud(new CloudType);

	CloudType::PointType p_nan;
	p_nan.x = std::numeric_limits<float>::quiet_NaN();
	p_nan.y = std::numeric_limits<float>::quiet_NaN();
	p_nan.z = std::numeric_limits<float>::quiet_NaN();
	cloud->push_back(p_nan);

	CloudType::PointType p_valid;
	p_valid.x = 1.0f;
	cloud->push_back(p_valid);

	std::cout << "size: " << cloud->points.size() << std::endl;

	std::vector<int> indices;
	pcl::removeNaNFromPointCloud(*cloud, *output_cloud, indices);
	std::cout << "size: " << output_cloud->points.size() << std::endl;
}
