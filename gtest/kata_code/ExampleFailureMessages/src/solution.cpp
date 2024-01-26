int alwaysFails(int n) {
  return n;
}

bool isEven(int n) {
	return alwaysFails(n) % 2 == 0;
}