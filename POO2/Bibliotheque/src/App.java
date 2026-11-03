package src;
import java.sql.SQLException;
import java.util.List;

import javax.swing.SwingUtilities;

import src.modele.Livre;
import src.vue.*;
import src.requete.*;

public class App {

    public static void main(String[] args) throws SQLException {
        RequeteBiblio re = new RequeteBiblio();
        String motCleInitial = "dune";
        List<Livre> livres = re.getLivresParMotCle(motCleInitial);
        // livres.add(new Livre("9780441363940", "Dune", "Frank Herbert", "Chilton Books", 412, 1965));
        // livres.add(new Livre("9782070360024", "L'Etranger", "Albert Camus", "Gallimard", 186, 1942));
        // livres.add(new Livre("9782253006329", "Le Petit Prince", "Antoine de Saint-Exupery", "Gallimard", 96, 1943));

        SwingUtilities.invokeLater(() -> {
            FenetreBiblio fenetreBiblio = new FenetreBiblio(livres, re, motCleInitial);
            fenetreBiblio.setVisible(true);
        });
        
    }
}