#include "sparsepoly.hpp"

int main()
{
	//��Ҵ��׽� A�� B ����
	SparsePoly A, B;

	//���׽� A �Է� �� Ȯ��
	A.read();
	A.display("Poly A: ");

	//���׽� B �Է� �� Ȯ��
	B.read();
	B.display("Poly B: ");

	//A�� B�� ���� ���� C�� ���� �� Ȯ��
	SparsePoly C;
	C.add(A, B);
	C.display("Poly C: ");
}