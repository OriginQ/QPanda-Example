#include "QPanda.h"
USING_QPANDA

int main()
{
	std::string filename = "testfile.txt";
	std::ofstream os(filename);
	os << R"(QINIT 4
                CREG 4
                DAGGER
                X q[1]
                X q[2]
                CONTROL q[1], q[2]
                RY q[0], (1.047198)
                ENDCONTROL
                ENDDAGGER
                MEASURE q[0], c[0]
                QIF c[0]
                H q[1]
                ELSE
                H q[2]
                RZ q[2], (2.356194)
                CU q[2], q[3], (3.141593, 4.712389, 1.570796, -1.570796)
                CNOT q[2], q[1]
                ENDQIF
                )";

	os.close();

	auto machine = initQuantumMachine(QMachineType::CPU);
	QProg prog = QPanda::convert_originir_to_qprog(filename, machine);

	std::cout <<
		convert_qprog_to_originir(prog, machine)
		<< std::endl;

	destroyQuantumMachine(machine);
	return 0;
}