package rave.construct.primitive;

import java.io.IOException;

import rave.common.Automata;
import rave.nodes.CoefficientalNode;
import rave.nodes.INode;
import rave.nodes.WithoutSettings;

public class Comma extends CoefficientalNode implements WithoutSettings {

	@Override
	public void execute(Automata state) {
		int c = 0;
		
		try {
			for(int i = 0; i < getCoefficient(); i++)
				c = System.in.read();
		} catch (IOException e) {
			c = 0;
		}
		
		if(c < 0)
			c = 0;
		
		state.tape.set(state.mp.getValue(), c);
	}

}
