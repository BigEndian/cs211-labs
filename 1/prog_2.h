int min(const int n1, const int n2, const int n3);
int max(const int n1, const int n2, const int n3);
double average(const int n1, const int n2, const int n3);

int min(const int n1, const int n2, const int n3)
{
	int _min = (n1 < n2) ? n1 : n2;
	_min = (_min < n3) ? _min : n3;
	return _min;
}
int max(const int n1, const int n2, const int n3)
{
	int _max = (n1 > n2) ? n1 : n2;
	_max = (_max > n3) ? _max : n3;
	return _max;
}
double average(const int n1, const int n2, const int n3)
{
	return ((double)n1+n2+n3) / 3.0;
}
