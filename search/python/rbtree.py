class Segment(object):
    L = 0   #Sweep Line
    def __init__(self,start_point,end_point):
        self.start = start_point
        self.end = end_point


    def __eq__(l,r):
        return True if l.start == r.start and l.end == r.end else False
    

    def __cmp__(l,r):
        '''The sequence is depend on the position of status line L'''
        p1 = l.start    #Left point of line1
        p2 = l.end      #right point of line1
        p3 = r.start    #Left point of line2
        p4 = r.end      #right point of line2
        l_dx = p2[0] - p1[0]
        l_dy = p2[1] - p1[1]
        r_dx = p4[0] - p3[0]
        r_dy = p4[1] - p3[1]
        dy = (l_dy * (StatusSegment.L - p1[0]) + p1[1] * l_dx) * r_dx - (r_dy * (StatusSegment.L - p3[0]) + p3[1] * r_dx) * l_dx
        return dy if dy else cmp(p2[1],p4[1])


class RBT(object):
    class Node(object):
        '''
        Node used in RBTree
        '''
        def __init__(self,key,value=None,color=False,N=1):
            self.key = key
            self.val = value
            self.color = color   #False for Black, True for Red
            self.N = N           #Total numbers of nodes in this subtree
            self.left = None
            self.right = None

        def __cmp__(l,r):
            return cmp(l.key,r.key)

        def __eq__(l,r):
            return True if l.key == r.key else False

        def __add__(l,r):
            l.value + r.value

        def merge(self,new_val):
            self.val.extend(new_val)

    def __init__(self):
        self.root = None

    #====================APIs====================#
    #=====Basic API

    def get(self,key):
        return  self.__get(self.root,key)

    def put(self,key,val):
        self.root = self.__put(self.root,key,val)
        self.root.color = False 

    def append(self,key,val):
        self.root = self.__append(self.root,key,val)
        self.root.color = False

    def delete(self,key):
        if not self.contains(key):
            raise LookupError('No such keys in rbtree. Fail to Delete')
        if self.__is_black(self.root.left) and self.__is_black(self.root.right):
            self.root.color = True
        self.root = self.__delete(self.root,key)
        if not self.is_empty(): 
            self.root.color = False

    def del_min(self):
        if self.is_empty(): 
            raise LookupError('Empty Red-Black Tree. Can\'t delete min')
        if self.__is_black(self.root.left) and self.__is_black(self.root.right):
            self.root.color = True
        self.root = self.__del_min(self.root)
        if not self.is_empty(): self.root.color = False

    def del_max(self):
        if self.is_empty():
            raise LookupError('Empty Red-Black Tree. Can\'t delete max')
        if self.__is_black(self.root.left) and self.__is_black(self.root.right):
            self.root.color = True
        self.root = self.__del_max(self.root)
        if not self.is_empty(): self.root.color = False 

    def size(self):
        return self.__size(self.root)

    def is_empty(self):
        return not self.root

    def contains(self,key):
        return bool(self.get(key))

    #=====Advance API
    def min(self):
        if self.is_empty():
            return None
        return self.__min(self.root).key

    def max(self):
        if self.is_empty():
            return None
        return self.__max(self.root).key

    def floor(self,key):
        pass

    def ceil(self,key):
        pass

    def rank(self,key):
        return self.__rank(self.root,key) 

    def keys(self):
        '''Return All Keys in the tree '''
        return self.__range(self.min(),self.max())

    def range(self,lo,hi):
        '''Take two keys. return keys between them'''
        q = []
        self.__range(self.root,q,lo,hi)
        return q

    def select(self,index):
        '''Given Index Return Corresponding key '''
        if not 0 <= index < self.size():
            return None
        return self.__select(self.root,index).key

    def width(self,lo,hi):
        '''Return the numbers of keys between lo and hi '''
        if lo > hi: 
            return 0
        if self.contains(hi):
            return self.rank(hi) - self.rank(lo) + 1
        else:
            return self.rank(hi) - self.rank(lo)
    
    #====================APIs====================#

    #===============Private Method===============#
    #=====Basic
    def __get(self,x,key):
        while x:
            tag = cmp(key,x.key)
            if tag < 0 : x = x.left
            elif tag > 0 :x = x.right
            else: return x.val

    def __put(self,h,key,val):
        if not h: 
            return self.Node(key,val,True,1)
        tag = cmp(key,h.key)
        if tag < 0: 
            h.left = self.__put(h.left,key,val)
        elif tag > 0: 
            h.right = self.__put(h.right,key,val)
        else: 
            h.val = val   #Update

        if self.__is_black(h.left) and self.__is_red(h.right):
            h = self.__rotate_left(h)
        if self.__is_red(h.left) and self.__is_red(h.left.left):
            h = self.__rotate_right(h)
        if self.__is_red(h.left) and self.__is_red(h.right):
            self.__flip_colors(h)
        h.N = self.__size(h.left) + self.__size(h.right) + 1
        return h

    def __append(self,h,key,val):
        if not h: 
            return self.Node(key,val,True,1)
        tag = cmp(key,h.key)
        if tag < 0: 
            h.left = self.__append(h.left,key,val)
        elif tag> 0: 
            h.right = self.__append(h.right,key,val)
        else: 
            h.merge(val)   #append.

        if self.__is_black(h.left) and self.__is_red(h.right):
            h = self.__rotate_left(h)
        if self.__is_red(h.left) and self.__is_red(h.left.left):
            h = self.__rotate_right(h)
        if self.__is_red(h.left) and self.__is_red(h.right):
            self.__flip_colors(h)
        h.N = self.__size(h.left) + self.__size(h.right) + 1
        return h

    def __del_min(self,h):
        if not h.left: #if h is empty:return None
            return None

        if self.__is_black(h.left) and self.__is_black(h.left.left):
            self.__move_red_left(h)
        h.left = self.__del_min(h.left) #Del recursive
        return self.__balance(h)

    def __del_max(self,h):
        if self.__is_red(h.left): 
            h = self.__rotate_right(h)
        if not h.right: 
            return None
        if self.__is_black(h.right) and self.__is_black(h.right.left):
            h = self.__move_red_right(h)
        h.right = self.__del_max(h.right)
        return self.__balance(h)

    def __delete(self,h,key):
        if key < h.key:
            if self.__is_black(h.left) and self.__is_black(h.left.left):
                h = self.__move_red_left(h)
            h.left = self.__delete(h.left,key)
        else:
            if self.__is_red(h.left):
                h = self.__rotate_right(h)
            if key == h.key and not h.right:
                return None
            if self.__is_black(h.right) and self.__is_black(h.right.left):
                h = self.__move_red_right(h)
            if key == h.key:#replace h with min of right subtree
                x = self.__min(h.right)
                h.key = x.key
                h.val = x.val
                h.right = self.__del_min(h.right)
            else:
                h.right = self.__delete(h.right,key)
        h = self.__balance(h)
        return h
    
    #=====Advance
    def __min(self,h):
        #Assume h is not null
        if not h.left:
            return h
        else:
            return self.__min(h.left)

    def __max(self,h):
        #Assume h is not null
        if not h.right:
            return h
        else:
            return self.__max(h.right)

    def __floor(self,h,key):
        pass

    def __ceil(self,h,key):
        pass

    def __rank(self,h,key):
        if not x:
            return 0
        tag = cmp(key,h.key)
        if tag < 0:
            return self.__rank(h.left,key)
        elif tag > 0:   #Key is bigger
            return self.__rank(h.right,key)+1+self.__size(h.left)
        else:   #Eq
            return self.size(h.left)

    def __select(self,h,index):
        '''assert h. assert 0 <= index < size(tree) '''
        l_size = self.__size(h.left)
        if l_size > index:
            return self.__select(h.left,index)
        elif l_size < index:
            return self.__select(h.right,index - l_size -1)
        else:
            return h

    def __range(self,h,q,lo,hi):
        if not h: 
            return
        tag_lo = cmp(lo,h.key)
        tag2_hi = cmp(hi,h.key)
        if tag_lo < 0:#lo key is lower than h.key
            self.__range(h.left,q,lo,hi)
        if tag_lo <=0 and tag_hi >=0:
            q.append(h.key)
        if tag_hi > 0 :# hi key is bigger than h.key
            self.__range(h.right,q,lo,hi)

    #===============Private Method===============#


    #===============Adjust Functions=============#
    def __rotate_right(self,h):
        x = h.left
        h.left,x.right = x.right,h
        x.color,x.N = h.color,h.N
        h.color,h.N = True,self.__size(h.left) + self.__size(h.right) + 1
        return x

    def __rotate_left(self,h):
        x = h.right
        h.right,x.left = x.left,h
        x.color,x.N = h.color,h.N
        h.color,h.N = True,self.__size(h.left) + self.__size(h.right) + 1
        return x

    def __flip_colors(self,h):
        h.color = not h.color
        h.left.color = not h.left.color
        h.right.color = not h.right.color

    def __move_red_left(self,h):
        self.__flip_colors(h)
        if self.__is_red(h.right.left):
            h = self.__rotate_left(h)
        return h

    def __move_red_right(self,h):
        self.__flip_colors(h)
        if self.__is_red(h.left.left):
            h = self.__rotate_right(h)
        return h

    def __balance(self,h):
        if self.__is_red(h.right): 
            h = self.__rotate_left(h)
        if self.__is_red(h.left) and self.__is_red(h.left.left): 
            h = self.__rotate_right(h)
        if self.__is_red(h.left) and self.__is_red(h.right):
            self.__flip_colors(h)
        h.N = self.__size(h.left) + self.__size(h.right) + 1
        return h
    
    #Class Method
    @staticmethod
    def __is_red(x):
        return False if not x else x.color

    @staticmethod
    def __is_black(x):
        return True  if not x else not x.color

    @staticmethod
    def __size(x):
        return 0 if not x else x.N
    #===============Adjust Functions=============#



if __name__ == '__main__':
    t = RBT()
    test_data = "SEARCHXMPL"

    print '=====testing is_empty()\nBefore Insertion'
    print t.is_empty()

    for letter in test_data:
        t.put(letter,[ord(letter)])
        print "Test Inserting:%s, tree size is %d"%(letter,t.size())
    print "After insertion it return:"
    print t.is_empty()
    print  "====test is_empty complete\n"


    print "=====Tesing Get method:"
    print "get 's' is "
    print t.get('S')
    print "get 'H' is "
    print t.get('H')

    print '==Trying get null key: get "F" is'
    print t.get('F')
    print "=====Testing Get method end\n\n"


    print '======test append method'
    print 'Orient key e is correspond with'
    print t.get('E')
    t.append('E',[4])
    print '==After append'
    print t.get('E')
    print "=====Testing Append method end\n\n" 


    print "====Tesing Min and Max"
    print "min key is:"
    print t.min()
    print "max key is"
    print t.max()
    print "try to delete min_key:"
    print "But first try:contain('A')"
    print t.contains('A')
    print "Now the new min key is "
    t.del_min()
    print "After deletion t.contains('A') is "
    print t.contains('A')

    print t.min()
    print "try to kill one more min key:"
    t.del_min()
    print t.min()
    print "try to delete max_key,New Max key is :"
    t.del_max()
    print t.max()
    print "=====Tesing Min and Max complete\n\n"



    print '=====Deleting Test'
    print t.size()
    t.delete('H')
    print t.size()

    print 'Delete a non-exists key:'
    try:    
        t.delete('F')
    except:
        print "*Look up error occur*"

    print "=====Testing Delete method complete"

 