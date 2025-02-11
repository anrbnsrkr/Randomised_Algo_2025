import subprocess
import matplotlib.pyplot as plt

cpp_program = "./hash.out"

runtime_array = []

for i in range(500):
    runtime_array.append(int(subprocess.run(cpp_program, capture_output=True, text=True).stdout.strip()))

plt.scatter(range(1,501),runtime_array, marker='x')
plt.title('Runtime of hash.out over 500 runs')
plt.xlabel('Run #')
plt.ylabel('Runtime (in ns)')
plt.show()