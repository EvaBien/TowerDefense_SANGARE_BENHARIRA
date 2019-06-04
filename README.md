Nous tentons ici de coder un jeu de type Tower Defense en c++ : le IMACat ATTACK.
Plus d'infos quand ce sera jouable
(Si ça l'est un jour)

OBJECTIF : Votre mission ? Empêcher les chats de renverser le vase de votre grand-mère.

Pour ce faire, vous avez plusieurs sources de distraction à votre disposition :
de l’herbe à chat
un jeu laser
une gamelle de croquette
un bol de lait
Chaque élément correspond ainsi à un type de tour du jeu Tower Defense, respectivement :
tour verte
tour rouge
tour jaune
tour bleue

Chaque tour a diverses caractéristique et un prix distinct. Vous pouvez placer une tour par case constructible tout en ayant conscience que celles-ci ont une portée limitée.

De même, il existe trois type de “recharge” pour les tours qui correspondent aux différents buildings, à même d’en modifier les caractéristiques :
sac de croquette = buildingstock
bouteille de lait = buildingweapon
pile = buildingradar


COMMENT JOUER ?
Pour lancer le jeu vous appuyez sur espace. 
Des vagues de monstres chats sont alors lancées à intervalle régulier.
Vous pouvez appuyer sur les touches q ou echap pour quitter avant la fin du jeu.

Pour construire une tour vous pressez la touche T et observez une modification de votre curseur, celui-ci affiche le type de tour que vous vous apprêtez à construire. Pour changer de tour vous pouvez cliquer au choix sur les touches 1, 2, 3 ou 4. 
Une fois que vous avez sélectionnez le type de tour que vous pouvez/voulez construire, vous pouvez cliquer sur la carte à l’endroit où vous souhaitez construire votre tour. Si la case sélectionnée est constructible et ne contient encore aucune tour ou building, votre tour est construite et vous perdez l’argent que cette tour coûtait.

De la même manière, pour placer une recharge, soit un building, vous cliquez sur la touche B puis au choix la touche 1, 2 ou 3.

Si vous souhaitez sortir du mode construction de tour, il vous faut recliquer sur T. De même avec building vous devez recliquer sur B. Si vous passez du mode construction de tour T à construction de building B et inversement, vous n’avez pas besoin de sortir du mode de construction au préalable, cliquer sur l’autre mode de construction vous fait automatiquement sortir du premier.

Vous rechargez votre cagnotte avec l’argent que vous gagnez à la mort de chaque monstre.
Si vous survivez à 20 vagues de monstres, vous avez gagné.
Au contraire, si un monstre atteint le vase de votre grand-mère en moins de 20 vagues d’attaques, vous avez perdu.

ENJOY !