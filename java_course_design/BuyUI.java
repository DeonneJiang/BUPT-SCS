package homework7;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;

import java.util.*;

public class BuyUI extends JDialog{
	private Controller controller;
	Sale saleinstance;
	public BuyUI( Controller p_controller) {
		setSize(800,600);
		controller = p_controller;
		saleinstance = new Sale();
		
		
		// crate the panel
				JPanel panel = new JPanel();
				
				
		// create the "purchase" button 
				JButton purchaseButton = new JButton("购买");
				
		// create the table which shows all the books
				DefaultTableModel model = new DefaultTableModel();
		        model.addColumn("ISBN");
		        model.addColumn("书名");
		        model.addColumn("单价");
		        model.addColumn("所属类型");
		        
		        JTable table = new JTable(model);
		        
		        
		        // add books to the table
		        for( BookSpecification book : controller.getBookCatalog().books){
		        	String s1 = new String(book.isbn);
		        	String s2 = new String(book.title);
		        	String s3 = Double.toString(book.price);
		        	String s4;
		        	switch(book.type) {
		        	case 1: s4  = "非教材类计算机图书"; break;
		        	case 2: s4  = "教材类图书"; break;
		        	case 3: s4  = "连环画类图书"; break;
		        	case 4: s4  = "养生类图书"; break;
		        	default : s4  = "其他"; break;
		        	}
		            Object a[] = {
		                s1,s2,s3,s4
		            };
		            model.addRow(a);
		        }		
		
		        JLabel quantityLabel = new JLabel("数量：");
		        JTextField quantityField = new JTextField(10);
		        
		        
		        //shopping cart
		        ShoppingCartUI cart = new ShoppingCartUI();
		        cart.setVisible(false);
		        setModal(false);
		        cart.setModal(false);
		        cart.setVisible(true);
		        saleinstance.addObserver(cart);
		        
		        
		        
		        purchaseButton.addActionListener(new ActionListener() {

					@Override
					public void actionPerformed(ActionEvent arg0) {
						// TODO Auto-generated method stub
						int row = table.getSelectedRow();
						String number = (String) model.getValueAt(row, 0);
						BookSpecification book = controller.getBookCatalog().getBookSpecification(number);
						int quantity = Integer.parseInt(quantityField.getText());
						SaleLineItem lineitem = new SaleLineItem(quantity,book);
						saleinstance.addlineItem(lineitem);
						saleinstance.notifyObservers();
					}
					
		        	
		        });
		        
		        
		        
		        panel.add(table);
		        panel.add(quantityLabel);
		        panel.add(quantityField);
		        panel.add(purchaseButton);
		        add(panel);
		        
		
	}
	
	
	
}
