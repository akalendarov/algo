auto compress(auto &v)
{
	auto w = v;
	sort(all(w));
	w.resize(unique(all(w)) - w.begin());

	for(auto &i : v)
	{
		i = binary_search(all(w), i) - w.begin();
	}
}
