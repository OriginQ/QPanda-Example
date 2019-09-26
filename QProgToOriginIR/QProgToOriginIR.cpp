#include "Core/QPanda.h"
USING_QPANDA

int main(void)
{
	auto qvm = initQuantumMachine();

	auto prog = CreateEmptyQProg();
	auto cir = CreateEmptyCircuit();

	auto q = qvm->allocateQubits(6);
	auto c = qvm->allocateCBits(6);


	cir << Y(q[2]) << H(q[2]);
	cir.setDagger(true);

	auto h1 = H(q[1]);
	h1.setDagger(true);

	prog << H(q[1])
		<< X(q[2])
		<< h1
		<< RX(q[1], 2 / PI)
		<< cir
		<< CR(q[1], q[2], PI / 2)
		<< MeasureAll(q, c);

	std::cout << transformQProgToOriginIR(prog, qvm) << std::endl;

	destroyQuantumMachine(qvm);
	return 0;
}