package homework7;

import java.util.ArrayList;

public class CompositeStrategy implements IPricingStrategy{

	ArrayList<IPricingStrategy> strategies;
	private String number;
	private String name;
	private int adaptType;
	
	public CompositeStrategy(ArrayList<IPricingStrategy> sstrategies, String snumber, String sname, int sadaptType) {
		strategies = sstrategies;
		number = snumber;
		name = sname;
		adaptType = sadaptType;
	}
	
	
	@Override
	public double getSubTotal(SaleLineItem item) {
		double smallest = Double.MAX_VALUE;
		for(IPricingStrategy s: strategies) {
			if( s.getSubTotal(item) < smallest) {
				smallest = s.getSubTotal(item);
			}
		}
		return smallest;
	}

	@Override
	public String getName() {
		return name;
	}

	@Override
	public String getNumber() {
		return number;
	}

	@Override
	public int    getAdaptType() {
		return adaptType;
	}
	
}
