import random

def generate_random_data(count=10000,method=random.randint,params=(0,10000)):
    return [random.randint(*params) for i in range(0,count)]


def generate_random_datafile(count=10000,path='./data',sep=' ',method=random.randint,params=(0,10000)):
    temp =[method(*params) for i in range(0,count)] 
    with open(path,'w') as dst:
        for i in temp:dst.write(str(i) + sep)
        
def load_from_file(path='./data',sep=' ',method=int):
    return [method(x) for x in open(path,'r').read().split() ]
            

def save_to_file(data,path='./data',sep=' ' ,method=str):
    with open(path,'w') as dst:
        for item in data: dst.write(method(item) + sep)


#Aux Funciton    
def isSorted(data,cmp):
    for i in range(1,len(data)):
        if cmp(data[i],data[i - 1]) < 0: return False
    return True 