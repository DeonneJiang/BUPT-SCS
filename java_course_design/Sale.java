package homework7;

import java.util.ArrayList;
import java.util.Observable;

public class Sale  extends Observable{
	
	ArrayList<SaleLineItem> items;

	public Sale() {
		items = new ArrayList<SaleLineItem>();
	}
	
	public double getTotal() {
		double total = 0;
		for( SaleLineItem i : items) {
			total = total + i.getSubTotal();
		}
		return total;
	}

	public void addlineItem(SaleLineItem s) {
		items.add(s);
		setChanged();
	}
	
	
	
}
