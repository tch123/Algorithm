import sys
import time
import auxiliary
import sort_functions as sf

funlist = {x:getattr(sf,x) for x in dir(sf) if not x.startswith('__')}

DATA = auxiliary.generate_random_data(10)
TRUE_DATA = DATA[:]
TRUE_DATA.sort()


def run(sort_fun):
    begin = time.time()
    sort_fun(DATA)
    end = time.time()

    if DATA == TRUE_DATA:
        print "==========Success!=========="
    else:
        print "=========Fail==========="

    print "Time Elapsed: %f"%(end-begin)
    #print DATA
    #print TRUE_DATA



def benchmark(fun_list,data):
    pass
    






if __name__ == '__main__':
    #auxiliary.generate_random_datafile(10)

    #Default setting
    algo = 'InsertionSort'
    #Parse from command line
    if len(sys.argv) > 1:
        algo = sys.argv[1]

    if algo == 'bm':
        benchmark(test_map)
        exit(0)

    print "Testing %s:"%algo
    run(funlist.get(algo))






