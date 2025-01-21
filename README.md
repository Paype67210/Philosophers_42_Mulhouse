<picture>
<img alt="Entête du dépôt Philosophers_42_Mulhouse." src="https://github.com/Paype67210/Philosophers_42_Mulhouse/blob/main/Tools/cover-philosophers.png">
</picture>

## 🚀 Objectifs du projet  
- Apprendre à manipuler les threads pour exécuter des tâches simultanément.  
- Utiliser des primitives de synchronisation telles que les mutex pour éviter les problèmes de **race conditions** et **deadlocks**.  
- Comprendre et implémenter des stratégies pour résoudre un problème classique d'accès concurrent aux ressources partagées.  

---

## 📖 Contexte  
X philosophes sont assis autour d'une table ronde, chacun ayant un plat et une fourchette à sa droite et à sa gauche. Leur cycle de vie se compose de trois actions : **manger**, **penser**, et **dormir**. Cependant, pour manger, chaque philosophe doit posséder les deux fourchettes adjacentes, ce qui peut entraîner des conflits d'accès.

---

## 💡 Compétences développées  
- Gestion des **threads** avec des bibliothèques spécifiques comme **pthread** (sous Unix).  
- Utilisation des mutex pour synchroniser l'accès à des ressources critiques.  
- Analyse des risques de blocages (deadlocks) et de famine dans des systèmes concurrents.  

---

## ⚙️ Requis techniques  
1. Implémenter la simulation avec un nombre variable de philosophes.  
2. Garantir l'absence de deadlocks tout en respectant les règles de base :  
   - Chaque philosophe doit avoir deux fourchettes pour manger.  
   - Un philosophe ne peut pas manger éternellement, il doit alterner entre manger, penser et dormir.  
3. Assurer une synchronisation précise en utilisant des **timestamps** pour indiquer le moment exact de chaque action.  

---

## 🧪 Tests et cas limites  
- Gestion correcte avec un nombre élevé de philosophes.  
- Vérification des comportements en cas de ressources limitées ou d'accès simultané.  
- Simulation fluide sans conditions de blocage ni d'incohérences.  

---

## 🛠️ Concepts clés abordés  
- **Threads et concurrence** : Exécution parallèle et indépendante de plusieurs tâches.  
- **Mutex et sémaphores** : Gestion fine de l'accès aux ressources partagées.  
- **Conditions de course** : Prévention des conflits dans l'accès aux données.  
- **Philosophes et gestion de ressources limitées** : Modélisation d’un problème algorithmique classique.  

---

## 🌟 Pourquoi ce projet est important ?  
Ce projet permet de comprendre les bases de la programmation concurrente, un concept essentiel dans le développement de systèmes modernes où l'exécution parallèle est courante. Le projet nous forme également à anticiper et résoudre des problèmes complexes liés à l'accès concurrent aux ressources.

