package homework7;

public class FlatRateStrategy implements IPricingStrategy{

	private String name;
	private String number;
	double discountPerBook;
	private int adaptType;
	
	public FlatRateStrategy(String snumber, String sname, double sdiscount, int sadapttype) {
		number = snumber;
		name = sname;
		discountPerBook = sdiscount;
		adaptType = sadapttype;
	}
	
	@Override
	public double getSubTotal(SaleLineItem item) {
		return (item.copies)*(item.bookSpec.getPrice())-discountPerBook;
	}

	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return name;
	}

	@Override
	public String getNumber() {
		// TODO Auto-generated method stub
		return number;
	}

	@Override
	public int getAdaptType() {
		// TODO Auto-generated method stub
		return adaptType;
	}

}
