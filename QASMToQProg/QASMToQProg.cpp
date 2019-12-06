#include "QPanda.h"
USING_QPANDA

int main()
{
	std::string filename = "testfile.txt";
	std::ofstream os(filename);
	os << R"(// test QASM file
        OPENQASM 2.0;
        include "qelib1.inc";
        qreg q[3];
        creg c[3];
        x q[0];
        x q[1];
        z q[2];
        h q[0];
        tdg q[1];
        measure q[0] -> c[0];
        measure q[1] -> c[1];
        measure q[2] -> c[2];
        )";

	os.close();

	auto machine = initQuantumMachine(QMachineType::CPU);
	QProg prog = convert_qasm_to_qprog(filename, machine);

	std::cout << convert_qprog_to_qasm(prog, machine) << std::endl;
	destroyQuantumMachine(machine);
	return 0;
}