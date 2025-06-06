FROM node:18.16.0

# copying backend files and setting the right permissions
WORKDIR /usr/src/app
COPY services/frontend/ .
RUN chown -Rh node:node /usr/src/app
RUN usermod -u 1000 -o node
RUN groupmod -g 1000 node

# copying entrypoint while still in root
COPY services/frontend/frontend-entrypoint.sh /usr/local/bin/docker-entrypoint
RUN chown node:node /usr/local/bin/docker-entrypoint

# using node user instead of root for security reasons
USER node
#RUN chmod +x /usr/local/bin/docker-entrypoint

# configuring npm permissions globally
RUN mkdir ~/.npm-global
RUN npm config set prefix '~/.npm-global'
RUN export PATH=~/.npm-global/bin:$PATH
RUN echo "export PATH=~/.npm-global/bin:$PATH" >> ~/.profile
RUN . ~/.profile

# installing necessary npm packages
#RUN npm install react-scripts
#RUN npm install



#ENV NODE_ENV production
#RUN npm ci --only=production

ENTRYPOINT [ "sh", "/usr/local/bin/docker-entrypoint"]
