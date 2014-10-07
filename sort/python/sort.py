#coding: gbk
import sys
import time
import auxiliary
import sort_functions


def benchmark(candidate):
    '''Run Benchmark'''
    #Size to run
    size_list = [10,100,500,1000,2000,4000,8000]
    mycmp = lambda l,r: -1 if l < r else 1 if l > r else 0 


    print 'Algorithms:\t ' + '\t\t'.join(candidate.keys())
    for size_item in size_list:
        result = []
        #Generate Random Testing data in different Size
        origin_A = auxiliary.generate_random_data(size_item)            
        for k,v in candidate.items():
            temp_A = origin_A[:]
            begin = time.time()
            v(temp_A,mycmp)
            result.append(time.time() - begin)
        print 'Size:%d:\t' % size_item + '\t\t'.join([str(x) for x in result]) + '\n'


#Testing Framework
def main(algo,size):
    '''Testing Framework'''
    #========----Update data----======== #
    #temp_A=auxiliary.generate_random_data(size)
    
    temp_data = auxiliary.load_from_file()
    print "Generate Complete! data length: %d" % len(temp_data)
    
    #========----Param Setting----=======#
    sorter = algo 
    mydata = temp_data
    mycmp = lambda l,r: -1 if l < r else 1 if l > r else 0
    
    #========----Before Sort----========#
    #print "=" * 20 + 'Before Sort' + '=' * 20
    print mydata

    #========------Sorting------========#
    begin = time.time()
    sorter(mydata,mycmp)
    end = time.time()
    
    elapse = end - begin
    #========----datafter Sort----========#
    #print "=" * 20 + 'datafter Sort' + '=' * 20
    print mydata

    print "#====Sorted!====# \n Time Elapse: %f" % elapse if auxiliary.isSorted(mydata,mycmp) else "#====Not Sorted!====#"
    return elapse


def DefalutSort(A,cmp):
    A.sort()







#unit test
if __name__ == '__main__':
    
    auxiliary.generate_random_datafile(10)

    algo = 'insertion'
    size = 1000
   
    function_map = {
        'selection':SelectionSort,
        'insertion':InsertionSort,

    }


    test_map = {
        'selection':SelectionSort,
        'insertion':InsertionSort,
    }



    if len(sys.argv) > 1:
        algo = sys.argv[1]

    if algo == 'benchmark':
        benchmark(test_map)
        exit(0)

    if len(sys.argv) > 2:
        size = int(sys.argv[2])

    print "%s is begin:"%algo
    main(function_map[algo],size)


    
