# updating packages 
npm install

# creating database scheme with prisma and populating with seed
npx prisma migrate dev --name "init"
npx prisma db seed

npm run start:dev