package homework7;

public class PercentageStrategy implements IPricingStrategy{

	
	int discountPercentage;
	private String number;
	private String name;
	private int adaptType;
	
	PercentageStrategy(String snumber, String sname, int sadapttype, int sdiscountpercentage){
		number = snumber;
		name = sname;
		adaptType = sadapttype;
		discountPercentage = sdiscountpercentage;
	}
	
	
	
	@Override
	public double getSubTotal(SaleLineItem item) {
		return item.copies*item.bookSpec.getPrice()*(100-discountPercentage)/100;
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
	public int getAdaptType() {
		return adaptType;
	}

}
