package homework7;

public class NoDiscountStrategy implements IPricingStrategy{

	@Override
	public double getSubTotal(SaleLineItem item) {
		// TODO Auto-generated method stub
		return (item.copies)*(item.bookSpec.getPrice());
	}

	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public String getNumber() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int getAdaptType() {
		// TODO Auto-generated method stub
		return 0;
	}
	
}
