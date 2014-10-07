

public class main {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
			int[] a = {124,345,923,928,582,258,025,262,515,205};
			Partition(a,0,a.length);
	}
	
	///p stand for pivot ,r stand for rear
	public static  void quickSort(int[] array,int p ,int r)
	{
		if(p<r){
			return;
		}
		 int q = Partition(array,p,r);
		 quickSort(array,a,q-1);
		 quickSort(array,q+1,r);
	}
	
	public static int Partition(int[] array,int p,int r){
		int key = array[p];
		int i = p;
		int j = r+1;
		while(true){
			while(array[++i]<key);
			while(array[--j]>key);
				if(i>=j){
					break;
				}
				int temp = array[j];
				array[j] = array[i];
				array[i] =temp;
		}
		array[p] = array[j];
		array[i] = key;
		return j;
		
	}
}
