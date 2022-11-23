import pandas as pd
import glob

algos = ('bubbleSort', 'insertionSort', 'mergeSort', 'quickSort', 'radixSort', 'shellSort')
base_folder = './PythonAlgorithms/outputs'

columns = ["ncalls","tottime","percall","cumtime","percall","filename:lineno(function)"]



def get_files_in_dir(dir, algorithm):
    dir += '/'+algorithm
    return glob.glob(dir+"/*.csv")



def avg_algo_stats(df: pd.DataFrame, algorithm: str) -> pd.DataFrame:
    sample_csvs = get_files_in_dir(base_folder, algorithm)

    for sample_file in sample_csvs:
        sample_reading = pd.read_csv(sample_file)
        sample_row = sample_reading[sample_reading['filename:lineno(function)'].str.contains(algorithm+"|radixLL") == True].reset_index(drop=True)
        #print(sample_row)
        #print(sample_row.loc[0, 'ncalls'])

        for column in columns[:-1]:
            cell = sample_row.loc[0, column]
            if isinstance(cell, str):
                cell = eval(cell)
            df.loc[algorithm, column] = df.loc[algorithm, column] + float(cell)
            #print(df.loc[algorithm, column])
        
    df.loc[[algorithm]] /= len(sample_csvs)
    print(df, '\n')





def main():
    df = pd.DataFrame(data=[[0] * len(columns)], columns = columns, index= list(algos))
    for algo in algos:
        avg_algo_stats(df, algo)
    
    df.to_csv(base_folder + "/runtimes.csv")


    

print([0]*10)
main()



