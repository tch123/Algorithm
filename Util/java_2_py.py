import os
import sys
import re



def address(filename):
    fh = open(filename,'r')
    content = fh.read()
    content = re.sub(r'(?s)\/\*(([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*)\*\/',r'#\1#',content)#/**/ Comment
    content = re.sub(r'(?m)^\s*(\*)','#',content)# leading * Comment
    content = re.sub('//','#',content)   #// Comment

    content = re.sub(r'[{}]','',content)
    content = re.sub(r'public\s*','',content)
    content = re.sub(r'private\s*','',content)

    with open(filename+'.md','w') as dst:
        dst.write(content)
    fh.close()

if __name__ == "__main__":
    filename = 'd:/RBT.java'
    try:
        filename = sys.argv[1]
    except:
        pass

    address(filename)
    
