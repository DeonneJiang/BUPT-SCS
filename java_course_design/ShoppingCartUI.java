package homework7;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;

public class ShoppingCartUI extends JDialog implements Observer{

	
	
	
	private JPanel panel = new JPanel();
	public ShoppingCartUI() {
		panel = new JPanel();
		add(panel);
	}

	@Override
	public void update(Observable arg0, Object arg1) {
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
				// crate the panel
						
						
						panel.removeAll();
						
						
						setSize(600,300);
						System.out.println("updated");
						Sale sale = (Sale)arg0;
						
						
						
				// create the "add book" button 
						JButton purchaseall = new JButton("支付");
						
						purchaseall.addActionListener( new ActionListener() {

							@Override
							public void actionPerformed(ActionEvent arg0) {
								// TODO Auto-generated method stub
								JOptionPane.showMessageDialog(null,"购买成功");
							}
							
						});
						
						
				// create the table which shows all the books
						DefaultTableModel model = new DefaultTableModel();
				        model.addColumn("ISBN");
				        model.addColumn("书名");
				        model.addColumn("单价");
				        model.addColumn("总价");
				        
				        double all  = 0;
				        JTable table = new JTable(model);
				        
				        for( SaleLineItem lineitem : sale.items) {
				        	String s1, s2, s3, s4;
				        	s1 = lineitem.bookSpec.isbn;
				        	s2 = lineitem.bookSpec.title;
				        	s3 = Double.toString(lineitem.bookSpec.getPrice());
				        	all  = all + lineitem.getSubTotal();
				        	s4 = Double.toString(lineitem.getSubTotal());
				        	Object a[] = {
				                    s1,s2,s3,s4
				                };
				        	
				        	model.addRow(a);
				        }
				        
				        
				        JLabel priceLabel = new JLabel("总金额:");
				        JTextField priceField = new JTextField(10);
				        
				        priceField.setText(Double.toString(all));
				        
				        panel.add(table);
				        panel.add(priceLabel);
				        panel.add(priceField);
				        panel.add(purchaseall);
				        
				  
				        setVisible(true);
	}

}
