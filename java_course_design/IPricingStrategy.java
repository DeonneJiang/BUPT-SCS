package homework7;

public interface IPricingStrategy {
	double getSubTotal( SaleLineItem item);
	String getName();
	String getNumber();
	int getAdaptType();
}
