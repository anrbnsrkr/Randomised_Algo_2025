import subprocess
import pandas as pd
import matplotlib.pyplot as plt

cpp_program_subset_100 = ["./hash.out", "100"]
cpp_program_subset_500 = ["./hash.out", "500"]
cpp_program_subset_1000 = ["./hash.out", "1000"]
cpp_program_subset_5000 = ["./hash.out", "5000"]
cpp_program_subset_10000 = ["./hash.out", "10000"]

runtime_array_subset_100 = []
runtime_array_subset_500 = []
runtime_array_subset_1000 = []
runtime_array_subset_5000 = []
runtime_array_subset_10000 = []

columns = ['Random Subset Size 100','Random Subset Size 500','Random Subset Size 1000','Random Subset Size 5000','Random Subset Size 10000']
index = ['< 0.5 ms','0.5 - 1 ms','1 - 1.5 ms','1.5 - 3 ms','3 - 3.5 ms','3.5 - 4 ms','4 - 9 ms','9 - 9.5 ms','9.5 - 10 ms','> 10 ms','Average Runtime (in ms)']
runtime_analysis = pd.DataFrame(0,index=index,columns=columns)

for i in range(1000):
    runtime_array_subset_100.append(int(subprocess.run(cpp_program_subset_100, capture_output=True, text=True).stdout.strip()))
    runtime_array_subset_500.append(int(subprocess.run(cpp_program_subset_500, capture_output=True, text=True).stdout.strip()))
    runtime_array_subset_1000.append(int(subprocess.run(cpp_program_subset_1000, capture_output=True, text=True).stdout.strip()))
    runtime_array_subset_5000.append(int(subprocess.run(cpp_program_subset_5000, capture_output=True, text=True).stdout.strip()))
    runtime_array_subset_10000.append(int(subprocess.run(cpp_program_subset_10000, capture_output=True, text=True).stdout.strip()))

sum = [0,0,0,0,0]

for i in range(1000):
    sum[0] += runtime_array_subset_100[i]
    sum[1] += runtime_array_subset_500[i]
    sum[2] += runtime_array_subset_1000[i]
    sum[3] += runtime_array_subset_5000[i]
    sum[4] += runtime_array_subset_10000[i]

for i in range(1000):

    runtime = runtime_array_subset_100[i]
    if runtime<500000:
        runtime_analysis.loc['< 0.5 ms', 'Random Subset Size 100']+=1
    elif runtime<=1000000:
        runtime_analysis.loc['0.5 - 1 ms', 'Random Subset Size 100']+=1
    elif runtime<=1500000:
        runtime_analysis.loc['1 - 1.5 ms', 'Random Subset Size 100']+=1
    elif runtime<=3000000:
        runtime_analysis.loc['1.5 - 3 ms', 'Random Subset Size 100']+=1
    elif runtime<=3500000:
        runtime_analysis.loc['3 - 3.5 ms', 'Random Subset Size 100']+=1
    elif runtime<=4000000:
        runtime_analysis.loc['3.5 - 4 ms', 'Random Subset Size 100']+=1
    elif runtime<=9000000:
        runtime_analysis.loc['4 - 9 ms', 'Random Subset Size 100']+=1
    elif runtime<=9500000:
        runtime_analysis.loc['9 - 9.5 ms', 'Random Subset Size 100']+=1
    elif runtime<=10000000:
        runtime_analysis.loc['9.5 - 10 ms', 'Random Subset Size 100']+=1
    else:
        runtime_analysis.loc['> 10 ms', 'Random Subset Size 100']+=1

    runtime = runtime_array_subset_500[i]
    if runtime<500000:
        runtime_analysis.loc['< 0.5 ms', 'Random Subset Size 500']+=1
    elif runtime<=1000000:
        runtime_analysis.loc['0.5 - 1 ms', 'Random Subset Size 500']+=1
    elif runtime<=1500000:
        runtime_analysis.loc['1 - 1.5 ms', 'Random Subset Size 500']+=1
    elif runtime<=3000000:
        runtime_analysis.loc['1.5 - 3 ms', 'Random Subset Size 500']+=1
    elif runtime<=3500000:
        runtime_analysis.loc['3 - 3.5 ms', 'Random Subset Size 500']+=1
    elif runtime<=4000000:
        runtime_analysis.loc['3.5 - 4 ms', 'Random Subset Size 500']+=1
    elif runtime<=9000000:
        runtime_analysis.loc['4 - 9 ms', 'Random Subset Size 500']+=1
    elif runtime<=9500000:
        runtime_analysis.loc['9 - 9.5 ms', 'Random Subset Size 500']+=1
    elif runtime<=10000000:
        runtime_analysis.loc['9.5 - 10 ms', 'Random Subset Size 500']+=1
    else:
        runtime_analysis.loc['> 10 ms', 'Random Subset Size 500']+=1

    runtime = runtime_array_subset_1000[i]
    if runtime<500000:
        runtime_analysis.loc['< 0.5 ms', 'Random Subset Size 1000']+=1
    elif runtime<=1000000:
        runtime_analysis.loc['0.5 - 1 ms', 'Random Subset Size 1000']+=1
    elif runtime<=1500000:
        runtime_analysis.loc['1 - 1.5 ms', 'Random Subset Size 1000']+=1
    elif runtime<=3000000:
        runtime_analysis.loc['1.5 - 3 ms', 'Random Subset Size 1000']+=1
    elif runtime<=3500000:
        runtime_analysis.loc['3 - 3.5 ms', 'Random Subset Size 1000']+=1
    elif runtime<=4000000:
        runtime_analysis.loc['3.5 - 4 ms', 'Random Subset Size 1000']+=1
    elif runtime<=9000000:
        runtime_analysis.loc['4 - 9 ms', 'Random Subset Size 1000']+=1
    elif runtime<=9500000:
        runtime_analysis.loc['9 - 9.5 ms', 'Random Subset Size 1000']+=1
    elif runtime<=10000000:
        runtime_analysis.loc['9.5 - 10 ms', 'Random Subset Size 1000']+=1
    else:
        runtime_analysis.loc['> 10 ms', 'Random Subset Size 1000']+=1

    runtime = runtime_array_subset_5000[i]
    if runtime<500000:
        runtime_analysis.loc['< 0.5 ms', 'Random Subset Size 5000']+=1
    elif runtime<=1000000:
        runtime_analysis.loc['0.5 - 1 ms', 'Random Subset Size 5000']+=1
    elif runtime<=1500000:
        runtime_analysis.loc['1 - 1.5 ms', 'Random Subset Size 5000']+=1
    elif runtime<=3000000:
        runtime_analysis.loc['1.5 - 3 ms', 'Random Subset Size 5000']+=1
    elif runtime<=3500000:
        runtime_analysis.loc['3 - 3.5 ms', 'Random Subset Size 5000']+=1
    elif runtime<=4000000:
        runtime_analysis.loc['3.5 - 4 ms', 'Random Subset Size 5000']+=1
    elif runtime<=9000000:
        runtime_analysis.loc['4 - 9 ms', 'Random Subset Size 5000']+=1
    elif runtime<=9500000:
        runtime_analysis.loc['9 - 9.5 ms', 'Random Subset Size 5000']+=1
    elif runtime<=10000000:
        runtime_analysis.loc['9.5 - 10 ms', 'Random Subset Size 5000']+=1
    else:
        runtime_analysis.loc['> 10 ms', 'Random Subset Size 5000']+=1

    runtime = runtime_array_subset_10000[i]
    if runtime<500000:
        runtime_analysis.loc['< 0.5 ms', 'Random Subset Size 10000']+=1
    elif runtime<=1000000:
        runtime_analysis.loc['0.5 - 1 ms', 'Random Subset Size 10000']+=1
    elif runtime<=1500000:
        runtime_analysis.loc['1 - 1.5 ms', 'Random Subset Size 10000']+=1
    elif runtime<=3000000:
        runtime_analysis.loc['1.5 - 3 ms', 'Random Subset Size 10000']+=1
    elif runtime<=3500000:
        runtime_analysis.loc['3 - 3.5 ms', 'Random Subset Size 10000']+=1
    elif runtime<=4000000:
        runtime_analysis.loc['3.5 - 4 ms', 'Random Subset Size 10000']+=1
    elif runtime<=9000000:
        runtime_analysis.loc['4 - 9 ms', 'Random Subset Size 10000']+=1
    elif runtime<=9500000:
        runtime_analysis.loc['9 - 9.5 ms', 'Random Subset Size 10000']+=1
    elif runtime<=10000000:
        runtime_analysis.loc['9.5 - 10 ms', 'Random Subset Size 10000']+=1
    else:
        runtime_analysis.loc['> 10 ms', 'Random Subset Size 10000']+=1

runtime_analysis.loc['Average Runtime (in ms)', 'Random Subset Size 100'] = float("{:.4f}".format(sum[0]/10**9))
runtime_analysis.loc['Average Runtime (in ms)', 'Random Subset Size 500'] = float("{:.4f}".format(sum[1]/10**9))
runtime_analysis.loc['Average Runtime (in ms)', 'Random Subset Size 1000'] = float("{:.4f}".format(sum[2]/10**9))
runtime_analysis.loc['Average Runtime (in ms)', 'Random Subset Size 5000'] = float("{:.4f}".format(sum[3]/10**9))
runtime_analysis.loc['Average Runtime (in ms)', 'Random Subset Size 10000'] = float("{:.4f}".format(sum[4]/10**9))

fig, ax = plt.subplots(figsize=(14, 4)) 
fig.suptitle('Hashtable Has 97 LL\'s, Executes 10000 Search Queries', fontsize=14, fontweight='bold')
ax.axis('tight')
ax.axis('off')

table = ax.table(cellText=runtime_analysis.values, 
         colLabels=columns, 
         rowLabels=index, 
         loc='center')

for (i, j), cell in table.get_celld().items():
    if i == 0:  
        cell.set_fontsize(16)
        cell.set_text_props(weight='bold')
    elif i>0 and j == -1:  
        cell.set_fontsize(16)
        cell.set_text_props(weight='bold')
    else:  
        cell.set_fontsize(16)  

plt.show()
